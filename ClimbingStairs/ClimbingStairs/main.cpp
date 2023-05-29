//
//  main.cpp
//  ClimbingStairs
//
//  Created by Arpit Batra on 22/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    int dp[50]={0};
    
    Solution(){
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
    }
    
    int climbStairs(int n) {
        if(dp[n]!=0)return dp[n];
        dp[n]=climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }

};


int main(int argc, const char * argv[]) {
    Solution sol;
    int n;
    while(true)
    {
        cout << "Enter the number" << endl;
        cin >> n;
        cout << sol.climbStairs(n) << endl;
    }
    return 0;
}
