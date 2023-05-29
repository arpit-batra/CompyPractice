//
//  main.cpp
//  MyCalender1
//
//  Created by Arpit Batra on 08/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int s,int e):start(s),end(e){};
};

struct IntervalTreeNode{
    Interval val;
    IntervalTreeNode *left;
    IntervalTreeNode *right;
//    IntervalTreeNode():val(0),left(nullptr),right(nullptr){}
    IntervalTreeNode(int x,int y):val(x,y),left(nullptr),right(nullptr){}
    IntervalTreeNode(int x,int y,IntervalTreeNode* left, IntervalTreeNode* right):val(x,y),left(left),right(right){}
};

class MyCalendar {
public:
    IntervalTreeNode* cal;
    MyCalendar() {
        cal = nullptr;
    }
    
    void printPreOrder(IntervalTreeNode *root){
        if(root!=nullptr){
            cout << "(" << root->val.start << "," << root->val.end << ")" << "    ";
            printPreOrder(root->left);
            printPreOrder(root->right);
        }
    }
    
    bool insert(IntervalTreeNode* curr, Interval i){
//        if(curr==nullptr){
////            curr = new IntervalTreeNode(i.start,i.end);
//            return true;
//        }
        int left = curr->val.start;
        int right = curr->val.end;
        int s = i.start;
        int e = i.end;
        bool temp;
//        cout << "left -> " << left << " right -> " << right << " s -> " << s << " e -> " << e << endl;
        if(s<right && e>left) return false;
        else if(s<left && e<=left){
            if(curr->left == nullptr){
                curr->left =  new IntervalTreeNode(i.start,i.end);
                return true;
            }
            else{
                return insert(curr->left,i);
            }
        }
        else if(s>=right && e>right){
            if(curr->right == nullptr){
                curr->right = new IntervalTreeNode(i.start,i.end);
                return true;
            }
            else{
                return insert(curr->right, i);
            }
        }
        return false;
    }

    bool book(int start, int end) {
        if(cal==nullptr){
            cal = new IntervalTreeNode(start,end);
            return true;
        }
        IntervalTreeNode* temp= cal;
//        printPreOrder(cal);
//        cout << endl;
        return insert(temp,Interval(start,end));
    }
};

int main(int argc, const char * argv[]) {
    MyCalendar cal;
    cout << cal.book(47,50) << endl;
    cout << cal.book(33,41) << endl;
    cout << cal.book(39,45) << endl;
    cout << cal.book(33,42) << endl;
    cout << cal.book(25,32) << endl;
    cout << cal.book(26,35) << endl;
    cout << cal.book(19,25) << endl;
    cout << cal.book(3,8) << endl;
    cout << cal.book(8,13) << endl;
    cout << cal.book(18,27) << endl;
//    cout << cal.book(39,45) << endl;
    return 0;
}
