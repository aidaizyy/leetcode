//
//  main.cpp
//  p289
//
//  Created by 张云尧 on 2017/5/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = (int)board.size();
        if (m == 0)
            return ;
        int n = (int)board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] * 2 - 1) * 10 + helper(board, i, j);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -7 || board[i][j] == 12 || board[i][j] == 13)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
    int helper(vector<vector<int>>& board, int i, int j) {
        int m = (int)board.size();
        int n = (int)board[0].size();
        int num = 0;
        if (i != 0) {
            if (j != 0 && board[i - 1][j - 1] > 0)
                ++num;
            if (board[i - 1][j] > 0)
                ++num;
            if (j != n - 1 && board[i - 1][j + 1] > 0)
                ++num;
        }
        if (j != 0 && board[i][j - 1] > 0)
            ++num;
        if (j != n - 1 && board[i][j + 1] > 0)
            ++num;
        if (i != m - 1) {
            if (j != 0 && board[i + 1][j - 1] > 0)
                ++num;
            if (board[i + 1][j] > 0)
                ++num;
            if (j != n - 1 && board[i + 1][j + 1] > 0)
                ++num;
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> board = {{0,1,0,0,1,1,0},{1,1,1,1,1,1,1},{1,1,0,0,0,0,1},{1,1,0,0,1,0,0}};
    s.gameOfLife(board);
    return 0;
}
