//
//  main.cpp
//  p129
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        sumNumbers(root, 0, res);
        return res;
    }
    void sumNumbers(TreeNode* node, int sum, int& res) {
        if (node == nullptr)
            return ;
        sum *= 10;
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr)
            res += sum;
        sumNumbers(node->left, sum, res);
        sumNumbers(node->right, sum, res);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
