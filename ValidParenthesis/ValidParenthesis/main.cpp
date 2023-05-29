//
//  main.cpp
//  ValidParenthesis
//
//  Created by Arpit Batra on 20/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
        stack<int>stk;
        int temp;
        for(int i=0;i<s.size();i++){
            switch (s[i]) {
                case '(':
                    stk.push(0);
                    break;
                case '{':
                    stk.push(1);
                    break;
                case '[':
                    stk.push(2);
                    break;
                case ')':
                    if(stk.empty()) return false;
                    temp = stk.top();
                    stk.pop();
                    if(temp!=0)return false;
                    break;
                case '}':
                    if(stk.empty()) return false;
                    temp = stk.top();
                    stk.pop();
                    if(temp!=1)return false;
                    break;
                case ']':
                    if(stk.empty()) return false;
                    temp = stk.top();
                    stk.pop();
                    if(temp!=2)return false;
                    break;
                    
                default:
                    break;
            }
        }
        if (stk.size()!=0) return false;
        return true;
}

int main(int argc, const char * argv[]) {
    
    string input;
    while(true){
        cout << "Enter the String ";
        cin >> input;
        cout << isValid(input) <<endl;}
    return 0;
}
