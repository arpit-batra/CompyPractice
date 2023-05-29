//
//  main.cpp
//  ValidSudoku
//
//  Created by Arpit Batra on 22/05/23.
//

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void printMatrix(vector<vector<int>> input){
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> validator(27,vector<int>(10,0));
//    printMatrix(validator);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            //Checking if the field is empty and if not then getting the number
            if(board[i][j]!='.'){
                int temp = (int)(board[i][j])-48;
                //Checking for the rows
                if(validator[9+i][temp]==1)return false;
                validator[9+i][temp]=1;
                //Checking for the columns
                if(validator[18+j][temp]==1)return false;
                validator[18+j][temp]=1;
                //Checking for the box
                //First Need to get the box number
                // -----------
                //| 0 | 1 | 2 |
                // -----------
                //| 3 | 4 | 5 |
                // -----------
                //| 6 | 7 | 8 |
                // -----------
                int boxNumber = ((int)(i/3))*3+(int)(j/3);
                if(validator[boxNumber][temp]==1)return false;
                validator[boxNumber][temp]=1;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> inputSudoku(9,vector<char>(9));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> inputSudoku[i][j];
        }
    }
    cout << "Valid -> " << isValidSudoku(inputSudoku) << endl;
    return 0;
}
