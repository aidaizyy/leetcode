//
//  main.cpp
//  p101
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        string str1 = travle(root->left, 1);
        string str2 = travle(root->right, 2);
        if (str1 == str2)
            return true;
        else
            return false;
    }
    
    string travle(TreeNode* node, int direction) {
        string res = "*";
        if (node == nullptr)
            return res;
        if (direction == 1) {
            res += travle(node->left, direction);
            res += travle(node->right, direction);
        } else {
            res += travle(node->right, direction);
            res += travle(node->left, direction);
        }
        res += node->val;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(13);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(21);
    root->left->right = new TreeNode(-48);
    root->right->left = new TreeNode(-48);
    root->right->right = new TreeNode(21);
    root->left->left->left = new TreeNode(32);
    root->left->right->right = new TreeNode(-13);
    root->right->left->left = new TreeNode(-13);
    root->right->right->left = new TreeNode(32);
    cout << s.isSymmetric(root) << endl;
    return 0;
}
