//
//  main.cpp
//  p36
//
//  Created by 张云尧 on 2017/3/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> temple(10, false);
        vector<vector<bool>> horizontal(9, temple);
        vector<vector<bool>> vertical(9, temple);
        vector<vector<bool>> block(9, temple);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    if (horizontal[i][v] || vertical[j][v] || block[i / 3 * 3 + j / 3][v])
                        return false;
                    horizontal[i][v] = true;
                    vertical[j][v] = true;
                    block[i / 3 * 3 + j / 3][v] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<char> tmp(9, '.');
    vector<vector<char>> board(9, tmp);
    //board[0][0] = '2';
    board[0][1] = '8';
    board[0][2] = '7';
    board[0][3] = '6';
    board[0][4] = '5';
    board[0][5] = '4';
    board[0][6] = '3';
    board[0][7] = '2';
    board[0][8] = '1';
    board[1][0] = '2';
    board[2][0] = '3';
    board[3][0] = '4';
    board[4][0] = '5';
    board[5][0] = '6';
    board[6][0] = '7';
    board[7][0] = '8';
    board[8][0] = '9';
    cout << s.isValidSudoku(board) << endl;
    return 0;
}
