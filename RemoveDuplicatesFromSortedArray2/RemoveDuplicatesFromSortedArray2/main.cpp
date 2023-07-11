//
//  main.cpp
//  RemoveDuplicatesFromSortedArray2
//
//  Created by Arpit Batra on 06/07/23.
//

#include <iostream>
#include <wchar.h>
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=0,j=1,currentNumber=nums[0],currentNumberCount=1;
    while(j<nums.size()){
        if(nums[j]==currentNumber){
            if(currentNumberCount==1){
                i++;
                nums[i]=currentNumber;
            }
            currentNumberCount++;
        } else{
            currentNumber = nums[j];
            i++;
            nums[i]=currentNumber;
            currentNumberCount = 1;
        }
//        cout << currentNumberCount << endl;
        j++;
    }
    return i+1;
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int n;
    cout << "Enter the length of the input array \n";
    cin >> n;
    vector<int> input(n);
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    int k = removeDuplicates(input);
    cout << k << "\n";
    printVector(input);
    return 0;
}
