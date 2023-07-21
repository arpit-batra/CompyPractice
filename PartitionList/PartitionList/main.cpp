//
//  main.cpp
//  PartitionList
//
//  Created by Arpit Batra on 19/07/23.
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

ListNode* partition(ListNode* head, int x) {
    ListNode *lessThanCounter=nullptr,*greaterThanCounter=nullptr,*counter=head,*firstOfGreaterThan=nullptr,*firstOfLessThan = nullptr;
    while(counter!=nullptr){
        if(counter->val<x){
            if(lessThanCounter==nullptr){
                firstOfLessThan = counter;
            }
            else{
                lessThanCounter->next = counter;
            }
            lessThanCounter = counter;
        } else {
            if(greaterThanCounter==nullptr){
                firstOfGreaterThan = counter;
            }
            else{
                greaterThanCounter->next=counter;
            }
            greaterThanCounter =counter;
        }
        counter = counter->next;
    }
    if(lessThanCounter!=nullptr)lessThanCounter->next = firstOfGreaterThan;
    if(greaterThanCounter!=nullptr)greaterThanCounter->next = nullptr;
    if(firstOfLessThan!=nullptr) return firstOfLessThan;
    else return firstOfGreaterThan;
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
        printLinkedList(input);
        cout << "Enter x\n";
        cin >> x;
        ans = partition(input,x);
        printLinkedList(ans);
    }
    return 0;
}
