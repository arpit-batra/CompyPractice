//
//  main.cpp
//  longestCommonPrefix
//
//  Created by Arpit Batra on 20/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void updateAnwerPosition(int newAns, int *ansStored){
    if(newAns< *ansStored){
        *ansStored = newAns;
    }
}



string longestCommonPrefix(vector<string>& strs) {
    if(strs[0]=="")return"";
    int positionInFirstStr = (int)strs[0].size()-1;
    cout << strs.size()<<endl;
    for(int i=1;i<strs.size();i++){
        int j=0;
        int firstStringSize =  (int)strs[0].size();
        int currStringSize = (int)strs[i].size();
        while(true){
            if(j>=firstStringSize-1 || j>=currStringSize-1){
                if(strs[0][j]==strs[i][j]){
                    if(j<positionInFirstStr){
                        positionInFirstStr=j;
                    }
                }else{
                    if(j-1<positionInFirstStr){
                        positionInFirstStr=j-1;
                    }
                }
                break;
            }
            else if( strs[0][j]!=strs[i][j]){
                if(j-1<positionInFirstStr){
                    positionInFirstStr = j-1;
                }
                break;
            }
            j++;
        }
//        cout << "Current Ans -> "<< positionInFirstStr << endl;
    }
    return strs[0].substr(0,positionInFirstStr+1);
}

int main(){
//    while(true){
//        int n;
//        cout << "Enter Length of the array" << endl;
//        cin >> n;
//        vector<string>input(n);
//        for(int i=0;i<n;i++){
//            cout << i+1 << endl;
//            cin >> input[i];
//        }
        vector<string>input;
        input.push_back("ab");
    input.push_back("a");
//    input.push_back("flow");

        cout << longestCommonPrefix(input) << endl;
//    }
}

