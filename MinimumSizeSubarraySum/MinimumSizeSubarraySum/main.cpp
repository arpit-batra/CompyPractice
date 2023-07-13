//
//  main.cpp
//  MinimumSizeSubarraySum
//
//  Created by Arpit Batra on 13/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int counter1=0,counter2=0,ans=INT_MAX,currSum=nums[0],n=(int)nums.size();
    while(true){
        if(currSum>=target){
            if((counter2-counter1)+1<ans){
                ans = (counter2-counter1)+1;
            }
            currSum-=nums[counter1];
            counter1++;
        }
        if(currSum<target){
            if(counter2==n-1)break;
            counter2++;
            currSum+=nums[counter2];
        }
    }
    if(ans == INT_MAX)return 0;
    return ans;
}

int main(int argc, const char * argv[]) {
    int n,target;
    vector<int>input;
    while(true){
        cout << "Enter length of array\n";
        cin >> n;
        input.resize(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout << "Enter the target\n";
        cin >> target;
        cout << minSubArrayLen(target, input) << endl;
    }
    return 0;
}
