//
//  main.cpp
//  p145
//
//  Created by 张云尧 on 2017/3/31.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        travel(res, root);
        return res;
    }
    void travel(vector<int>& res, TreeNode* node) {
        if (node == nullptr)
            return;
        travel(res, node->left);
        travel(res, node->right);
        res.push_back(node->val);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
