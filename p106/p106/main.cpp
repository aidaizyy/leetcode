//
//  main.cpp
//  p106
//
//  Created by 张云尧 on 2017/4/6.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode* buildTree(vector<int>::iterator il, vector<int>::iterator ir, vector<int>::iterator pl, vector<int>::iterator pr) {
        if (il == ir)
            return nullptr;
        auto pos = find(il, ir, *(pr - 1));
        TreeNode *root = new TreeNode(*(pr - 1));
        root->left = buildTree(il, pos, pl, pl + (pos - il));
        root->right = buildTree(pos + 1, ir, pl + (pos - il), pr - 1);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
