//
//  main.cpp
//  ProductOfArrayExceptSelf
//
//  Created by Arpit Batra on 03/08/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void printVector(vector<T> input){
    int n= (int)input.size();
    for(int i=0;i<n;i++){
        cout << input[i] << " ";
    }
    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int>ans;
    int zeroCounts = 0, n = (int)nums.size(),arrayProduct=1;
    for(int i=0;i<n;i++){
        if(nums[i]==0)zeroCounts++;
        else arrayProduct = arrayProduct*nums[i];
    }
    if(zeroCounts>1){
        for(int i=0;i<n;i++)ans.push_back(0);
    } else if (zeroCounts == 1){
        for(int i=0;i<n;i++){
            if(nums[i]==0) ans.push_back(arrayProduct);
            else ans.push_back(0);
        }
    } else {
        for(int i=0;i<n;i++){
            ans.push_back(arrayProduct/nums[i]);
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    vector<int> input,ans;
    while(true){
        cout << "Enter the length of the array \n";
        cin >> n;
        input.resize(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        printVector(input);
        ans = productExceptSelf(input);
        printVector(ans);
    }
    return 0;
}


