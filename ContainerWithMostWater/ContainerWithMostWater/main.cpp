//
//  main.cpp
//  ContainerWithMostWater
//
//  Created by Arpit Batra on 21/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int i,j;
    int answer = 0,tempArea;
    i=0;
    j=(int)height.size()-1;
    while(i<j){
        tempArea= min(height[i], height[j])*(j-i);
        if(tempArea>answer)answer=tempArea;
        if(height[i]<height[j])i++;
        else if(height[i]>height[j])j--;
        else{
            i++;
            j--;
        }
    }
    return answer;
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
        cout <<maxArea(input)<<'\n';
    }
    return 0;
}
