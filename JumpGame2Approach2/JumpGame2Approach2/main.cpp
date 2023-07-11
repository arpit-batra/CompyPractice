//
//  main.cpp
//  JumpGame2Approach2
//
//  Created by Arpit Batra on 11/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int jump(vector<int>& nums) {
    if(nums.size()==1)return 0;
    
//    int numberOfSteps = 1,startingPoint=0,n=(int)nums.size(),largestLeap,largestLeapIndex;
//    largestLeap = 0;
//    for(int i=startingPoint;i<= startingPoint + nums[startingPoint] && i<n;i++){
//        if(nums[i]+i>=(n-1)){
//            return numberOfSteps+1;
//        }
//        if(nums[i]+i>largestLeap){
//            largestLeap = nums[i]+i;
//            largestLeapIndex = i;
//        }
//    }
    int numberOfSteps =1, stepIndex = 0, stepValue = nums[0], n = (int)nums.size(),largestReachableIndex = nums[0],maxStepFinder =0;
            
    for(int i=0;i<n;i++){
        if(nums[i]+i>=(n-1)){
            return numberOfSteps+1;
        }
        if(nums[i]+i>maxStepFinder){
            maxStepFinder =nums[i]+i;
            stepIndex = i;
            stepValue = nums[i];
        }
        if(i==largestReachableIndex){
            numberOfSteps++;
            largestReachableIndex = stepIndex + stepValue;
            maxStepFinder = 0;
        }
    }
    return 0;
}


void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int n,ans;
    while(true){
        cout << "Enter the length of the input array \n";
        cin >> n;
        vector<int> input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        ans = jump(input);
        cout << ans << endl;
        //        printVector(input);
    }
    return 0;
}

