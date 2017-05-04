//
//  main.cpp
//  p222
//
//  Created by 张云尧 on 2017/5/3.
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
    int countNodes(TreeNode* root) {
        int res = 0;
        int height = getHeight(root);
        while(root != nullptr) {
            if (getHeight(root->right) == height - 1) {
                res += 1 << (height - 1);
                root = root->right;
            } else {
                res += 1 << (height - 2);
                root = root->left;
            }
            --height;
        }
        return res;
    }
    int getHeight(TreeNode* root) {
        return root == nullptr ? 0 : getHeight(root->left) + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
