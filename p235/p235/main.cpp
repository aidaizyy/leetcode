//
//  main.cpp
//  p235
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
        int minv = std::min(p->val, q->val);
        int maxv = std::max(p->val, q->val);
        if (root->val > maxv)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < minv)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
