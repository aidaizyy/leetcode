//
//  main.cpp
//  p95
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int begin, int end) {
        vector<TreeNode*> res;
        if (begin > end) {
            res.push_back(nullptr);
            return res;
        }
        if (begin == end) {
            res.push_back(new TreeNode(begin));
            return res;
        }
        vector<TreeNode*> left, right;
        for (int i = begin; i <= end; ++i) {
            left = generateTrees(begin, i - 1);
            right = generateTrees(i + 1, end);
            for (TreeNode* lnode : left) {
                for (TreeNode* rnode : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.generateTrees(0);
    return 0;
}
