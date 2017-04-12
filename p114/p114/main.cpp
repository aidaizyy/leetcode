//
//  main.cpp
//  p114
//
//  Created by 张云尧 on 2017/4/13.
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
    void flatten(TreeNode* root) {
        TreeNode* node = root;
        while (node != nullptr) {
            TreeNode* l = node->left;
            node->left = nullptr;
            flatten(l, node);
            node = node->right;
        }
    }
    void flatten(TreeNode* node, TreeNode*& prev) {
        if (node == nullptr)
            return ;
        TreeNode* l = node->left;
        TreeNode* r = node->right;
        TreeNode* next = prev->right;
        prev->right = node;
        node->left = nullptr;
        node->right = next;
        flatten(r, node);
        flatten(l, node);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    s.flatten(root);
    return 0;
}
