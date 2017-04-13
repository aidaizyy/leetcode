//
//  main.cpp
//  p199
//
//  Created by 张云尧 on 2017/4/13.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideView(root, 0, res);
        return res;
    }
    void rightSideView(TreeNode* node, int height, vector<int>& res) {
        if (node == nullptr)
            return ;
        if (res.size() == height)
            res.push_back(node->val);
        res[height] = node->val;
        rightSideView(node->left, height + 1, res);
        rightSideView(node->right, height + 1, res);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
