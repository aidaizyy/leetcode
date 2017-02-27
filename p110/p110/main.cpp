//
//  main.cpp
//  p110
//
//  Created by 张云尧 on 2017/2/27.
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
    bool travle(TreeNode* node, int& height) {
        height = 0;
        if (node == nullptr) {
            return true;
        }
        int h1 = 0;
        int h2 = 0;
        if (!travle(node->left, h1) || !travle(node->right, h2))
            return false;
        if (h1 - h2 >= -1 && h1 - h2 <= 1) {
            height = max(h1, h2) + 1;
            return true;
        } else
            return false;
    }
    
    bool isBalanced(TreeNode* root) {
        int height;
        return travle(root, height);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    cout << s.isBalanced(root) << endl;
    return 0;
}
