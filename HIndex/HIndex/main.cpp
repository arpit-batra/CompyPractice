//
//  main.cpp
//  HIndex
//
//  Created by Arpit Batra on 02/08/23.
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

//
//bool cmp(int a,int b){
//    return b<a;
//}

int hIndex(vector<int>& citations) {
    int n=(int)citations.size();
    int i = n-1;
    sort(citations.begin(),citations.end());
    while(n-i<=citations[i] && i>=0){
        i--;
    }
    return n-i-1;
}

int main(int argc, const char * argv[]) {
    int n;
    vector<int> input;
    while(true){
        cout << "Enter the length of the array \n";
        cin >> n;
        input.resize(n);
        for(int i=0;i<n;i++){
            cin >> input[i];
        }
        printVector(input);
        cout << hIndex(input) << endl;
    }
    
    return 0;
}
