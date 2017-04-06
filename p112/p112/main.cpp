//
//  main.cpp
//  p112
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0)
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
