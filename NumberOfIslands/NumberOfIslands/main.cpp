//
//  main.cpp
//  NumberOfIslands
//
//  Created by Arpit Batra on 09/08/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    void coverIsland(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&visited){
        if(i>=0 && j>=0 && i<(int)grid.size() && j<(int)grid[0].size() && grid[i][j]=='1' && visited[i][j]==0){
    //        cout << "Visiting -> "<< i << "*"<<j<<endl;
            visited[i][j]=1;
            coverIsland(i+1,j, grid, visited);
            coverIsland(i-1, j, grid, visited);
            coverIsland(i, j+1, grid, visited);
            coverIsland(i, j-1, grid, visited);
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int ans=0,m=(int)grid.size(),n=(int)grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    ans++;
                    coverIsland(i,j,grid,visited);
                }
            }
        }
        return ans;
    }

int main(int argc, const char * argv[]) {
    int n,m;
    while(true){
        cout << "Enter number of rows" << endl;
        cin >> m;
        cout << "Enter number of columns" << endl;
        cin >> n;
        vector<vector<char>>input(m,vector<char>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> input[i][j];
            }
        }
        cout << numIslands(input) << endl;
    }
    return 0;
}
