//
//  main.cpp
//  p538
//
//  Created by 张云尧 on 2017/4/2.
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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;
        helper(sum, node);
        return root;
    }
    void helper(int& sum, TreeNode* node) {
        if (node == nullptr)
            return ;
        helper(sum, node->right);
        node->val += sum;
        sum = node->val;
        helper(sum, node->left);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
