//
//  main.cpp
//  p103
//
//  Created by 张云尧 on 2017/4/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        queue.push(root);
        travel(res, queue, 1);
        return res;
    }
    void travel(vector<vector<int>>& res, queue<TreeNode*> que, int height) {
        res.push_back(vector<int>());
        stack<TreeNode*> tmp;
        int n = (int)que.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = que.front();
            if (node == nullptr) {
                que.pop();
                continue;
            }
            res[height - 1].push_back(node->val);
            if (height % 2 == 1) {
                tmp.push(node->left);
                tmp.push(node->right);
            } else {
                tmp.push(node->right);
                tmp.push(node->left);
            }
            que.pop();
        }
        while (!tmp.empty()) {
            que.push(tmp.top());
            tmp.pop();
        }
        if (res.back().empty()) {
            res.pop_back();
            return ;
        }
        travel(res, que, height + 1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    s.zigzagLevelOrder(root);
    return 0;
}
