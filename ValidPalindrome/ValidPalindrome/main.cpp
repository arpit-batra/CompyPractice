//
//  main.cpp
//  ValidPalindrome
//
//  Created by Arpit Batra on 29/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValidChar(char c){
    return ((c<='z' && c>='a')||(c<='Z' && c>='A') ||(c<='9' && c>='0'));
}

bool isPalindrome(string s) {
    int diff = (int)('a'-'A');
    int i=0,j=(int)s.length()-1;
    while(i<j){
        if(!isValidChar(s[i])){
            i++;
        } else{
            if(!isValidChar(s[j])){
                j--;
            }
            else{
                if(!( s[i]==s[j] || (((int)s[i]-s[j]==diff || (int)s[j]-s[i]==diff) && s[i]>'9' && s[j] > '9'))){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    string s;
    while(true){
        cout << "Enter the string"<< endl;
        getline(cin,s);
        cout << isPalindrome(s) << endl;
    }
    return 0;
}
