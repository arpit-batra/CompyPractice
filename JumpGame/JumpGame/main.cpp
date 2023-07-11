//
//  main.cpp
//  JumpGame
//
//  Created by Arpit Batra on 10/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool canJump(vector<int>& nums) {
    int maxReachablePoint=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0 && maxReachablePoint<=i && i!=(nums.size()-1)){
            return false;
        }
        if(i+nums[i]>maxReachablePoint){
            maxReachablePoint = i+nums[i];
        }
    }
    return true;
}


void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int n;
    bool ans;
    while(true){
        cout << "Enter the length of the input array \n";
        cin >> n;
        vector<int> input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        ans = canJump(input);
        cout << ans << endl;
        //        printVector(input);
    }
    return 0;
}

