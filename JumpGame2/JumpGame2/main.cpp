//
//  main.cpp
//  JumpGame2
//
//  Created by Arpit Batra on 10/07/23.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int jump(vector<int>& nums) {
    if(nums.size()==1)return 0;
    int n=(int)nums.size(),tempMin;
    vector<int>maxReachPoint(n),minStepsToEnd(n);
    for(int i=0;i<n;i++)maxReachPoint[i]=nums[i]+i;
    minStepsToEnd[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if(nums[i]==0)minStepsToEnd[i]=INT_MAX;
        else{
            tempMin = INT_MAX;
//            cout << "i -> "<<i <<endl;
            for(int j=i+1;j<= min(maxReachPoint[i],n-1);j++){
                if(minStepsToEnd[j]<tempMin){
                    tempMin = minStepsToEnd[j];
                }
//                cout << "      j -> " << j << endl;
            }
            
//                    cout << "i -> "<<i<<" tempMin+1 -> "<< tempMin+1 << " tempMin -> "<< tempMin << endl;
            if(tempMin == INT_MAX)minStepsToEnd[i]=INT_MAX;
            else minStepsToEnd[i]=tempMin+1;
        }
        }
    return minStepsToEnd[0];
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

