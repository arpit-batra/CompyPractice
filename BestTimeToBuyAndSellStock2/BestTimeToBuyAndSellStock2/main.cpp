//
//  main.cpp
//  BestTimeToBuyAndSellStock2
//
//  Created by Arpit Batra on 21/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    int ans=0,n=(int)prices.size();
    for(int i=0;i<n-1;i++){
        if(prices[i]<prices[i+1]){
            ans+=prices[i+1]-prices[i];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        cout << "Enter vector Length\n";
        cin >> n;
        vector<int>input(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        cout <<maxProfit(input)<<'\n';
    }
    return 0;
}
