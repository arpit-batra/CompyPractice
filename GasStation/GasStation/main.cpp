//
//  main.cpp
//  GasStation
//
//  Created by Arpit Batra on 21/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=(int)gas.size(),gasSum=0,costSum=0;
    for(int i=0;i<n;i++)gasSum+=gas[i];
    for(int i=0;i<n;i++)costSum+=cost[i];
    if(costSum>gasSum)return -1;
    int diff,tempCummalativeSum=0,ans=0,lowestCummalativeSum = INT_MAX;
    for(int i=0;i<n;i++){
        diff = gas[i]-cost[i];
        tempCummalativeSum=tempCummalativeSum+diff;
        if(tempCummalativeSum<lowestCummalativeSum){
            lowestCummalativeSum=tempCummalativeSum;
            ans=i;
        }
    }
    if(ans==n-1)return 0;
    return ans+1;
}

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        cout << "Enter vector Length\n";
        cin >> n;
        cout << "Enter Gas Array\n";
        vector<int>gasInput(n);
        for(int i=0;i<n;i++){
            cin >> gasInput[i];
        }
        
        cout << "Enter Cost Array\n";
        vector<int>costInput(n);
        for(int i=0;i<n;i++){
            cin >> costInput[i];
        }
        cout <<canCompleteCircuit(gasInput,costInput)<<'\n';
    }
    return 0;
}
