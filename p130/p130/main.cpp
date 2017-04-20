//
//  main.cpp
//  p130
//
//  Created by 张云尧 on 2017/4/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = (int)board.size();
        if (m == 0)
            return ;
        int n = (int)board[0].size();
        vector<vector<bool>> exist(m, vector<bool>(n, true));
        queue<int> queue;
        for (int j = 0; j < n; ++j)
            if (board[0][j] == 'O')
                queue.push(j);
        for (int j = 0; j < n; ++j)
            if (board[m - 1][j] == 'O')
                queue.push((m - 1) * n + j);
        for (int i = 1; i < m - 1; ++i)
            if (board[i][0] == 'O')
                queue.push(i * n);
        for (int i = 1; i < m - 1; ++i)
            if (board[i][n - 1] == 'O')
                queue.push(i * n + n - 1);
        while (!queue.empty()) {
            int tmp = queue.front();
            queue.pop();
            if (tmp < 0 || tmp >= m * n)
                continue;
            int i = tmp / n;
            int j = tmp % n;
            if (board[i][j] == 'X' || !exist[i][j])
                continue;
            exist[i][j] = false;
            queue.push(tmp + 1);
            queue.push(tmp - 1);
            queue.push(tmp - n);
            queue.push(tmp + n);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> board {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);
    return 0;
}
