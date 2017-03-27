//
//  main.cpp
//  p79
//
//  Created by 张云尧 on 2017/3/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (helper(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool helper(vector<vector<char>>& board, int i, int j, string& word, int pos) {
        if (pos == word.size())
            return true;
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return false;
        if (board[i][j] != word[pos])
            return false;
        board[i][j] *= -1;
        bool res = helper(board, i - 1, j, word, pos + 1) ||
        helper(board, i + 1, j, word, pos + 1) ||
        helper(board, i, j - 1, word, pos + 1) ||
        helper(board, i, j + 1, word, pos + 1);
        board[i][j] *= -1;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << s.exist(board, "ABCCED") << endl;
    return 0;
}
