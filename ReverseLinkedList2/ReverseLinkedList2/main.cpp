//
//  main.cpp
//  ReverseLinkedList2
//
//  Created by Arpit Batra on 25/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void printLinkedList(ListNode* head){
    ListNode* counter = head;
    while(counter!=nullptr){
        cout << counter->val << "->";
        counter = counter->next;
    }
    cout << "null \n";
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head->next==nullptr)return head;
    if(right-left!=0){
        ListNode *justBeforeStart,*start,*end,*justAfterEnd=nullptr,*counter1,*counter2,*counter3=nullptr,*counter=head;
    
        //Assigning start and justBeforeStart
        if(left==1){
            justBeforeStart=nullptr;
            start = head;
        } else {
            for(int i=0;i<left-2;i++){
                counter=counter->next;
            }
            justBeforeStart = counter;
            start = counter->next;
        }
    
        // Reversing the portion of List that needs to be reversed
        counter1 = start;
        counter2 = counter1->next;
        if(counter2!=nullptr) counter3=counter2->next;
        for(int i=0;i<right-left;i++){
            counter2->next = counter1;
            counter1=counter2;
            counter2=counter3;
            if(counter3!=nullptr ){
                counter3=counter3->next;
            } //TODO one more condition will come
        }
        
        
        //Attaching the reversed list to original
        
        end = counter1;
        justAfterEnd = counter2;
        //    cout << "justBeforeStart -> " << justBeforeStart->val << endl;
//            cout << "start -> " << start->val << endl;
//            cout << "end -> " << end->val << endl;
//            cout << "justAfterEnd -> " << justAfterEnd->val << endl;
        start->next = justAfterEnd;
        if(justBeforeStart!=nullptr) {
            justBeforeStart->next = end;
            return head;
        } else {
            return end;
        }
    } else {
        return head;
    }
}


int main(int argc, const char * argv[]) {
    int n,temp,left,right;
    
    while(true){
        ListNode *listCounter = new ListNode();
        ListNode *input = listCounter;
        ListNode *ans;
        cout << "Enter the number of entries in the linked list\n";
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> temp;
            listCounter->val = temp;
            if(i!=n-1){
                ListNode* tempNode = listCounter;
                listCounter = new ListNode();
                tempNode->next = listCounter;
            }
        }
        cout << "Input List\n";
        printLinkedList(input);
        cout << "Enter Left\n";
        cin >> left;
        cout << "Enter Right\n";
        cin >> right;
        ans = reverseBetween(input, left, right);
        printLinkedList(ans);
    }
    return 0;
}

