//
//  main.cpp
//  p230
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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        travel(res, root, k);
        return res;
    }
    bool travel(int& res, TreeNode* node, int& k) {
        if (node == nullptr)
            return false;
        if (travel(res, node->left, k))
            return true;
        if (k == 1) {
            res = node->val;
            return true;
        };
        --k;
        if (travel(res, node->right, k))
            return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
