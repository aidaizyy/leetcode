//
//  main.cpp
//  p212
//
//  Created by 张云尧 on 2017/3/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


struct TrieNode {
    struct TrieNode* next[26];
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrieTree(words);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                helper(res, board, root, i, j);
        return res;
    }
    void helper(vector<string>& res, vector<vector<char>>& board, TrieNode* root, int i, int j) {
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
            return ;
        char ch = board[i][j];
        if (ch < 0)
            return ;
        if (root->next[ch - 'a'] == nullptr)
            return ;
        if (root->next[ch - 'a']->word != "") {
            res.push_back(root->next[ch - 'a']->word);
            root->next[ch - 'a']->word = "";
        }
        board[i][j] *= -1;
        helper(res, board, root->next[ch - 'a'], i - 1, j);
        helper(res, board, root->next[ch - 'a'], i + 1, j);
        helper(res, board, root->next[ch - 'a'], i, j - 1);
        helper(res, board, root->next[ch - 'a'], i, j + 1);
        board[i][j] *= -1;
    }
    TrieNode* buildTrieTree(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string str : words) {
            TrieNode* node = root;
            for (char ch : str) {
                if (node->next[ch - 'a'] == nullptr) {
                    node->next[ch - 'a'] = new TrieNode();
                }
                node = node->next[ch - 'a'];
            }
            node->word = str;
        }
        return root;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    s.findWords(board, words);
    return 0;
}
