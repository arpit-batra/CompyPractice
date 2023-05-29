//
//  main.cpp
//  ValidTriangleNumber
//
//  Created by Arpit Batra on 28/04/23.
//


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool comparator(int a,int b){
    return a<b;
}

int findIndexAtleastOneLessThanN(int initialPosition, vector<int>b){
    int i=initialPosition;
    int number = b[i];
    while(i>=0){
        if(b[i]!=number)return i;
        i--;
    }
    return 0;
}

int positionOfAInArrayB(int a,int startPoint, vector<int>b){
    int start=startPoint,end=(int)b.size()-1,mid;
    while(start<end){
        cout << "Sum -> " << a << " Starting point -> " << startPoint << " start -> " << start << " end -> " << end << endl;4
        mid=(start+end)/2;
        if(b[mid]==a)return findIndexAtleastOneLessThanN(mid, b) ;//find index of number which is alteast one less than this
        if(start+1==end)return start;
        if(b[mid]>a)end = mid;
        if(b[mid]<a)start=mid;
    }
    return findIndexAtleastOneLessThanN(start, b);
}


int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(),comparator);
    int ans=0;
    for(int i=0;i<nums.size()-2;i++){
        ans+=positionOfAInArrayB(nums[i]+nums[i+1],i+2,nums)-(i+2)+1;
        cout << "ans => " << ans << endl;
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
        cout <<triangleNumber(input)<<'\n';
    }
    return 0;
}
