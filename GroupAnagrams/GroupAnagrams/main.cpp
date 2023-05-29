//
//  main.cpp
//  GroupAnagrams
//
//  Created by Arpit Batra on 17/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            map<char,int>charMap;
            for(int j=0;j<strs[i].length();j++){
                charMap[strs[i][j]]++;
            }
            m[charMap].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        map<map<char,int>,vector<string>>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            vector<string>anagrams;
            for(int i=0;i< it->second.size();i++){
                anagrams.push_back(it->second[i]);
            }
            ans.push_back(anagrams);
        }
        return ans;
    }

int main(int argc, const char * argv[]) {
    int n;
    vector<vector<string>> ans;
    while(true){
        cout << "Enter Length of the Array" << endl;
        cin >> n;
        vector<string> input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        ans = groupAnagrams(input);
        for(int i=0;i<ans.size();i++){
            cout << "[ ";
            for(int j=0;j<ans[i].size();j++){
                cout << "\""<<ans[i][j] << "\", ";
            }
            cout << " ] \n";
        }
    }
    return 0;
}
