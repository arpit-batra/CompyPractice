//
//  main.cpp
//  RemoveDuplicatesFromSortedList2
//
//  Created by Arpit Batra on 21/07/23.
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


ListNode* deleteDuplicates(ListNode* head) {
        
    
    ListNode *confirmedTillHere=nullptr,*counter=head,*ansStarting=nullptr;
    int currNum;
    while(counter!=nullptr){
        if(counter->next!=nullptr){
            if(counter->val == counter->next->val){
                currNum = counter->val;
                while(counter!=nullptr && counter->val==currNum){
//                    cout << "duplicates -> " << counter->val << endl;
                    counter = counter->next;
                    if(counter==nullptr && confirmedTillHere!=nullptr)confirmedTillHere->next=nullptr;
                }
            }else{
//                cout << "val != Next val ->  " << counter->val << endl;
                if(ansStarting == nullptr) ansStarting = counter;
                if(confirmedTillHere==nullptr)confirmedTillHere = counter;
                else {
                    confirmedTillHere->next = counter;
                    confirmedTillHere = counter;
                }
                counter=counter->next;
            }

        } else{
//            cout <<"Last Num -> " << counter->val << endl;
            if(ansStarting==nullptr)ansStarting = counter;
            if(confirmedTillHere==nullptr)confirmedTillHere = counter;
            else{
                confirmedTillHere->next = counter;
                confirmedTillHere = counter;
            }
                
            counter = counter->next;
        }
        
    }
    
    
    
    //Approach 2
//    if(counter->next->next==nullptr){
//        if(counter->val != counter->next->val)
//        {
//            //Add counter->next
//        } else {
//            if(counter->val!=counter->next->val && counter->next->val != counter->next->next->val){
//                //Add counter->next
//            }
//        }
//    }
    return ansStarting;
}

void printLinkedList(ListNode* head){
    ListNode* counter = head;
    while(counter!=nullptr){
        cout << counter->val << "->";
        counter = counter->next;
    }
    cout << "null \n";
}


int main(int argc, const char * argv[]) {
    int n,temp,x;
    
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
        ans = deleteDuplicates(input);
        printLinkedList(ans);
    }
    return 0;
}
