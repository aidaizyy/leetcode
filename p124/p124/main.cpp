//
//  main.cpp
//  p124
//
//  Created by 张云尧 on 2017/4/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
    int maxPathSum(TreeNode* node, int& res) {
        if (node == nullptr)
            return 0;
        int m = maxPathSum(node->left, res);
        int n = maxPathSum(node->right, res);
        res = max(res, m + n + node->val);
        res = max(res, max(max(m, n), 0) + node->val);
        return max(max(m, n), 0) + node->val;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
