//
//  main.cpp
//  RotateArray
//
//  Created by Arpit Batra on 07/07/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getNextIndex(int curIndex,int shift, int n){
    int nextIndex;
    if(curIndex+shift>=n){
        nextIndex = curIndex+shift-n;
    }else{
        nextIndex = curIndex + shift;
    }
    return nextIndex;
}


void rotate(vector<int>& nums, int k) {
    int shift,curIndex, nextIndex,curTemp,nextTemp,numberOfLoops,innerLoops;
    shift = k%nums.size();
    if(shift!=0){
        numberOfLoops = gcd((int)nums.size(), shift);
        cout << numberOfLoops<<endl;
        innerLoops = (int)nums.size()/numberOfLoops;
        for(int j=0;j<numberOfLoops;j++){
            curIndex = j;
            curTemp = nums[curIndex];
            for(int i=0;i<innerLoops;i++){
                nextIndex = getNextIndex(curIndex,shift,(int)nums.size());
                nextTemp = nums[nextIndex];
                nums[nextIndex] = curTemp;
                curTemp = nextTemp;
                curIndex = nextIndex;
            }
        }
    }
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int n,k;
    while(true){
        cout << "Enter the length of the input array \n";
        cin >> n;
        vector<int> input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout << "Enter k\n";
        cin >> k;
        rotate(input,k);
        printVector(input);
    }
    return 0;
}
