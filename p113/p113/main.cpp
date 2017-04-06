//
//  main.cpp
//  p113
//
//  Created by 张云尧 on 2017/4/6.
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSum(res, path, root, sum);
        return res;
    }
    void pathSum(vector<vector<int>>& res, vector<int>& path, TreeNode* node, int sum) {
        if (node == nullptr)
            return ;
        sum -= node->val;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr && sum == 0)
            res.push_back(path);
        pathSum(res, path, node->left, sum);
        pathSum(res, path, node->right, sum);
        path.pop_back();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
