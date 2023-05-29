//
//  main.cpp
//  IntersectionOfMultipleArrays
//
//  Created by Arpit Batra on 09/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<vector<int>>& nums) {
    int theCountArray[1001];
    for(int i=0;i<1001;i++)theCountArray[i]=0;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            theCountArray[nums[i][j]]++;
        }
    }
//    for(int i=0;i<1001;i++){
//        cout << theCountArray[i] << " ";
//    }
//    cout << endl;
//    cout << nums.size() << endl;
    vector<int> ans;
    for(int i=0;i<1001;i++){
        if(theCountArray[i]==nums.size())
            ans.push_back(i);
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    int n,tempN;
    cout << "Enter Number of Arrays" << endl;
    cin >> n;
    vector<vector<int>>v;
//    cout << v.size()<< endl;
    for(int i=0;i<n;i++){
        cout << "Enter size of this Array" << endl;
        cin >> tempN;
        vector<int> tempV(tempN);
        for(int j=0;j<tempN;j++){
            cin >> tempV[j];
        }
        v.push_back(tempV);
    }
//    cout << v.size()<< endl;
    vector<int>ans = intersection(v);
    for(int i=0;i<ans.size();i++){
        cout << ans[i]<<" ";
    }
    cout << endl;
    return 0;
}
