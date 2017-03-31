//
//  main.cpp
//  p98
//
//  Created by 张云尧 on 2017/3/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -1, -1);
    }
    bool isValidBST(TreeNode* node, int min, int max) {
        if (node == nullptr)
            return true;
        if (min != -1 && node->val <= min)
            return false;
        if (max != - 1 && node->val >= max)
            return false;
        return isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
