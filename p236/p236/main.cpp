//
//  main.cpp
//  p236
//
//  Created by 张云尧 on 2017/3/21.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode* s = lowestCommonAncestor(root->left, p, q);
        TreeNode* t = lowestCommonAncestor(root->right, p, q);
        if (s != nullptr && t != nullptr)
            return root;
        if (s == nullptr)
            return t;
        if (t == nullptr)
            return s;
        return nullptr;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
