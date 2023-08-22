//
//  main.cpp
//  LinkedListCycle
//
//  Created by Arpit Batra on 22/08/23.
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

bool hasCycle(ListNode *head) {
    if(head==nullptr || head->next == nullptr || head->next->next==nullptr)return false;
    if(head->next->next==head)return true;
    int forwardGoingNodes = 2,backwardGoingNodes = 0;
    ListNode *firstPointer=head,*secondPointer=head->next,*thirdPointer=secondPointer->next;
    firstPointer->next = nullptr;
    while(true){
//        cout << "Second Pointer value -> "<< secondPointer->val << endl << "forwardGoingNodes -> " << forwardGoingNodes << endl;
        secondPointer->next = firstPointer;
        if(thirdPointer == nullptr)break;
        firstPointer = secondPointer;
        secondPointer = thirdPointer;
        forwardGoingNodes++;
        thirdPointer = thirdPointer->next;
    }
    while(secondPointer!=nullptr){
        secondPointer = secondPointer->next;
        backwardGoingNodes++;
        if(backwardGoingNodes>forwardGoingNodes)
        {
//            cout << "fgn -> " << forwardGoingNodes << endl << "bgn -> " << backwardGoingNodes << endl;
            return true;
        }
            
    }
//    cout << "fgn -> " << forwardGoingNodes << endl << "bgn -> " << backwardGoingNodes << endl;
    if(forwardGoingNodes == backwardGoingNodes)return false;
    else return true;
}


int main(int argc, const char * argv[]) {
    ListNode *first = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);
    
    first->next = second;
    second->next = third;
    third->next = fourth;
//    fourth->next = second;
    
    cout << "starting" << endl;
    
    cout << hasCycle(first) << endl;
    
//
//    int n,temp,left,right;
//
//    while(true){
//        ListNode *listCounter = new ListNode();
//
//        ListNode *input = listCounter;
//        ListNode *ans;
//        cout << "Enter the number of entries in the linked list\n";
//        cin >> n;
//        for(int i=0;i<n;i++){
//            cin >> temp;
//            listCounter->val = temp;
//            if(i!=n-1){
//                ListNode* tempNode = listCounter;
//                listCounter = new ListNode();
//                tempNode->next = listCounter;
//            }
//        }
//        cout << "Input List\n";
//        printLinkedList(input);
//
//        printLinkedList(ans);
//    }
    return 0;
}

