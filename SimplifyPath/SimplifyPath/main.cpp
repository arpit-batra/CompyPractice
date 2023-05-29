//
//  main.cpp
//  SimplifyPath
//
//  Created by Arpit Batra on 15/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string path) {
    stack<string> s;
    int j=0;
    string temp,ans;
    for(int i=1;i<path.size();i++){
        if(path[i]=='/'||i==path.size()-1){
            if(i==path.size()-1 && path[i]!='/'){
                temp = path.substr(j+1);
            }
            else{
                temp = path.substr(j+1,i-j-1);
            }
            if(temp=="" || temp=="."){}
            else if(temp==".."){
                if(!s.empty())s.pop();
            }
            else{
                s.push(temp);
            }
            j=i;
        }
    }
    while(!s.empty()){
        temp = s.top();
        s.pop();
        ans.insert(0, "/"+temp);
    }
    if(ans.empty())return "/";
    return ans;
}

int main(int argc, const char * argv[]) {
    string s;
//    cout << "Cehck"<<endl;
    while(true)
    {
        cout << "Enter The String"<<endl;
        cin >> s;
        cout << simplifyPath(s)<< endl;
    }
    return 0;
}
