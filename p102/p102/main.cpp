//
//  main.cpp
//  p102
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void trave(TreeNode* node, int height, vector<vector<int>>& res) {
        if (node == nullptr)
            return ;
        if (res.size() < height) {
            vector<int> v;
            res.push_back(v);
        }
        trave(node->left, height+1, res);
        trave(node->right, height+1, res);
        res[height-1].push_back(node->val);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        trave(root, 1, res);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = s.levelOrder(root);
    return 0;
}
