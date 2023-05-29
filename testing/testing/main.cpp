//
//  main.cpp
//  testing
//
//  Created by Arpit Batra on 19/04/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
//    Symbol       Value
//    I             1
//    V             5
//    X             10
//    L             50
//    C             100
//    D             500
//    M             1000
    int answer = 0;
    for(int i=0;i<s.length();i++){
        switch (s[i]) {
            //*******
            //***I***
            //*******
            case 'I':
                if(i<s.length()-1){
                    if(s[i+1]=='V' || s[i+1]=='X'){
                        answer--;
                    }
                    else{
                        answer++;
                    }
                }
                else{
                    answer++;
                }
                break;
            //*******
            //***X***
            //*******
            case 'X':
                if(i<s.length()-1){
                    if(s[i+1]=='L' || s[i+1]=='C'){
                        answer-=10;
                    }
                    else{
                        answer+=10;
                    }
                }
                else{
                    answer+=10;
                }
                break;
            //*******
            //***C***
            //*******
            case 'C':
                if(i<s.length()-1){
                    if(s[i+1]=='D' || s[i+1]=='M'){
                        answer-=100;
                    }
                    else{
                        answer+=100;
                    }
                }
                else{
                    answer+=100;
                }
                break;
            //*******
            //***V***
            //*******
            case 'V':
                answer+=5;
                break;
            //*******
            //***L***
            //*******
            case 'L':
                answer+=50;
                break;
            //*******
            //***D***
            //*******
            case 'D':
                answer+=500;
                break;
            //*******
            //***M***
            //*******
            case 'M':
                answer+=1000;
                break;

            default:
                break;
        }
    }
    return answer;
    
    }

int main(int argc, const char * argv[]) {
    while(true){
        string input;
        cin >> input;
        cout << romanToInt(input) << endl;
    }
    return 0;
}
