//
//  main.cpp
//  HouseRobber
//
//  Created by Arpit Batra on 22/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
//    int robbery(vector<int>nums,int end){
//        if(end==0)return nums[0];
//        if(end==1)return max(nums[0],nums[1]);
//        return max(robbery(nums, end-1),robbery(nums, end-2)+nums[end]);
//    }
    
    int rob(vector<int>& nums) {
        int n=(int)nums.size();
        if(n==1)return nums[0];
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    int n;
    while(true){
        cout << "Enter vector lenght\n";
        cin >> n;
        vector<int>input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout << sol.rob(input) << endl;
    }
    return 0;
}
