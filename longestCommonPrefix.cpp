//
//  longestCommonPrefix.cpp
//  testing
//
//  Created by Arpit Batra on 20/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    return "";
    }

int main(){
    while(true){
        int n;
        cout << "Enter Length of the array" << endl;
        cin >> n;
        vector<string>input(n);
        for(int i=0;i<n;i++){
            cout << i+1 << endl;
            cin >> input[i];
        }
        cout << longestCommonPrefix(input);
    }
}
