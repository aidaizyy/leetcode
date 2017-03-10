//
//  main.cpp
//  p337
//
//  Created by 张云尧 on 2017/3/10.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <queue>
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
    int rob(TreeNode* root) {
        int l, r;
        return helper(root, l, r);
    }
    int helper(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(root->left, ll, lr);
        r = helper(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << s.rob(root) << endl;
    return 0;
}
