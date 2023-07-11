//
//  main.cpp
//  ReversePolishNotation
//
//  Created by Arpit Batra on 11/07/23.
//

#include <iostream>
#include <bits/stdc++.h>
//#include <string>


using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int>evaluationStack;
    int t1,t2,ans;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
        {
            t1 = evaluationStack.top();
            evaluationStack.pop();
            t2 = evaluationStack.top();
            evaluationStack.pop();
            if(tokens[i]=="+"){
                ans = t2+t1;
            } else if(tokens[i]=="-"){
                ans = t2-t1;
            } else if(tokens[i]=="*"){
                ans = t2*t1;
            } else {
                ans = t2/t1;
            }
            evaluationStack.push(ans);
        } else{
            evaluationStack.push(stoi(tokens[i]));
        }
    }
    return evaluationStack.top();
}

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        cout << "Enter the length of the input string\n";
        cin >> n;
        vector<string>input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout << evalRPN(input) <<"\n";
    }
    return 0;
}
