//
//  main.cpp
//  WordBreak
//
//  Created by Arpit Batra on 18/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//bool startsWith(string s, string sub){
//    for(int i=0;i<sub.size();i++){
//        if(sub[i]!=s[i]){
//            return false;
//        }
//    }
//    return true;
//}
//
//
//bool wordBreak(string s, vector<string>& wordDict) {
//    bool ans = false;
//    int n = (int)wordDict.size();
//    for(int i=0;i<n;i++){
//        if(startsWith(s,wordDict[i])){
//            if(s.compare(wordDict[i])==0){
//                return true;
//            } else{
//                ans = ans || wordBreak(s.substr(wordDict[i].size()), wordDict);
//            }
//
//        }
//    }
//    return ans;
//}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = (int)s.size(),wordSize;
    vector<int>dp(n,0);
    for(int i=0;i<n;i++){
        for(string word:wordDict){
            wordSize = (int)word.size();
            if(i-wordSize+1 >= 0){
                if(s.substr(i-wordSize+1,word.size()).compare(word)==0 && (i-wordSize<0 || dp[i-wordSize]==1)){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
//    for(int i=0;i<n;i++){
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    return (bool)dp[n-1];
}






int main(int argc, const char * argv[]) {
    int n;
    vector<string> input;
    string s;
    while(true){
        cout << "Enter length of Dictionary\n";
        cin >> n;
        input.resize(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout << "Enter string s\n";
        cin >> s;
        cout << wordBreak(s, input) << endl;
    }
    return 0;
}
