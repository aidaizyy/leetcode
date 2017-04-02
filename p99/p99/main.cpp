//
//  main.cpp
//  p99
//
//  Created by 张云尧 on 2017/4/2.
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        TreeNode* first = nullptr;
        TreeNode* last = nullptr;
        recoverTree(first, last, root);
        if (first != nullptr)
            swap(first->val, last->val);
    }
    void recoverTree(TreeNode*& first, TreeNode*& last, TreeNode* node) {
        if (node == nullptr)
            return ;
        recoverTree(first, last, node->left);
        if (first == nullptr) {
            if (last != nullptr && last->val > node->val)
                first = last;
        } else {
            if (first->val < node->val) {
                swap(first->val, last->val);
                first = nullptr;
            }
        }
        last = node;
        recoverTree(first, last, node->right);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    s.recoverTree(root);
    return 0;
}
