//
//  main.cpp
//  Candy
//
//  Created by Arpit Batra on 04/08/23.
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

//int candy(vector<int>& ratings) {
//    int n = (int)ratings.size(),candyArrayCorrectTill=-1,min,ans=0;
//    vector<int>candyArray(n);
//    for(int i=0;i<n;i++){
//        if(candyArrayCorrectTill == i-1){
//            //Start Making the incorrect candy array
//            candyArray[i]=0;
//        } else {
//            if(ratings[i]>ratings[i-1]){
//                candyArray[i] = candyArray[i-1]+1;
//            } else if(ratings[i]<ratings[i-1]){
//                candyArray[i] = candyArray[i-1]-1;
//            }
//        }
//        if(i==n-1 || ratings[i]==ratings[i+1]){
//            //Make candyArray till i correct
//            //Finding the least number in this incorrect candyArray
//            min = INT_MAX;
//            for(int j=candyArrayCorrectTill+1;j<=i;j++){
//                if(candyArray[j]<min)min = candyArray[j];
//            }
//            for(int j=candyArrayCorrectTill+1;j<=i;j++){
//                candyArray[j]=candyArray[j]+(1-min);
//            }
//            candyArrayCorrectTill=i;
//        }
//    }
//    for(int i=0;i<n;i++){
//        ans+=candyArray[i];
//        cout << candyArray[i] <<" ";
//    }
//    cout << endl;
//    return ans;
//}

int candy(vector<int>& ratings) {
    int n=(int)ratings.size(),ans=0;
    vector<int>candyArray(n,1);
    for(int i=0;i<n-1;i++){
        if(ratings[i+1]>ratings[i])candyArray[i+1]=candyArray[i]+1;
    }
    for(int i=n-1;i>0;i--){
        if(ratings[i-1]>ratings[i] && candyArray[i-1]<=candyArray[i])candyArray[i-1]=candyArray[i]+1;
    }
    for(int i=0;i<n;i++){
        ans+=candyArray[i];
        cout << candyArray[i] <<" ";
    }
    cout << endl;
    return ans;
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
        cout <<  candy(input) << endl;
    }
    return 0;
}

