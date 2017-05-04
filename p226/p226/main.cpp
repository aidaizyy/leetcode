//
//  main.cpp
//  p226
//
//  Created by 张云尧 on 2017/5/4.
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
