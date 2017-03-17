//
//  main.cpp
//  p37
//
//  Created by 张云尧 on 2017/3/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /*
    //12ms
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> temple(10, false);
        vector<vector<bool>> horizontal(9, temple);
        vector<vector<bool>> vertical(9, temple);
        vector<vector<bool>> block(9, temple);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    horizontal[i][v] = true;
                    vertical[j][v] = true;
                    block[i / 3 * 3 + j / 3][v] = true;
                }
            }
        }
        helper(board, horizontal, vertical, block, 0);
    }
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& horizontal, vector<vector<bool>>& vertical, vector<vector<bool>> block, int p) {
        for (int i = p; i < 81; ++i) {
            int x = i / 9;
            int y = i % 9;
            if (board[x][y] == '.') {
                int b = x / 3 * 3 + y / 3;
                int v;
                for (v = 1; v <= 9; ++v) {
                    if (horizontal[x][v] || vertical[y][v] || block[b][v])
                        continue;
                    horizontal[x][v] = true;
                    vertical[y][v] = true;
                    block[b][v] = true;
                    board[x][y] = v + '0';
                    if (helper(board, horizontal, vertical, block, p + 1))
                        return true;
                    horizontal[x][v] = false;
                    vertical[y][v] = false;
                    block[b][v] = false;
                    board[x][y] = '.';
                }
                if (v == 10)
                    return false;
            }
        }
        return true;
    }
    */
    
    //12ms
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0);
    }
    bool helper(vector<vector<char>>& board, int p) {
        for (int i = p; i < 81; ++i) {
            if (p == 17) {
                
            }
            int x = i / 9;
            int y = i % 9;
            if (board[x][y] == '.') {
                int k;
                for (k = 1; k <= 9; ++k) {
                    if (valid(board, x, y, k)) {
                        board[x][y] = k + '0';
                        if (helper(board, p + 1))
                            return true;
                        board[x][y] = '.';
                    }
                }
                if (k == 10)
                    return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<char>>& board, int x, int y, int v) {
        for (int i = 0; i < 9; ++i) {
            if (i != y && board[x][i] == v + '0')
                return false;
            if (i != x && board[i][y] == v + '0')
                return false;
        }
        int r = x / 3;
        int c = y / 3;
        for (int i = r * 3; i < r * 3 + 3; ++i)
            for (int j = c * 3; j < r * 3 + 3; ++j)
                if (i != x && j != y && board[i][j] == v + '0')
                    return false;
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> temple(10, false);
        vector<vector<bool>> horizontal(9, temple);
        vector<vector<bool>> vertical(9, temple);
        vector<vector<bool>> block(9, temple);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '0';
                    horizontal[i][v] = true;
                    vertical[j][v] = true;
                    block[i / 3 * 3 + j / 3][v] = true;
                }
            }
        }
        helper(board, horizontal, vertical, block, 0);
    }
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& horizontal, vector<vector<bool>>& vertical, vector<vector<bool>> block, int p) {
        for (int i = p; i < 81; ++i) {
            int x = i / 9;
            int y = i % 9;
            if (board[x][y] == '.') {
                int b = x / 3 * 3 + y / 3;
                int v;
                for (v = 1; v <= 9; ++v) {
                    if (horizontal[x][v] || vertical[y][v] || block[b][v])
                        continue;
                    horizontal[x][v] = true;
                    vertical[y][v] = true;
                    block[b][v] = true;
                    board[x][y] = v + '0';
                    if (helper(board, horizontal, vertical, block, p + 1))
                        return true;
                    horizontal[x][v] = false;
                    vertical[y][v] = false;
                    block[b][v] = false;
                    board[x][y] = '.';
                }
                if (v == 10)
                    return false;
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
    s.solveSudoku(board);
    return 0;
}
