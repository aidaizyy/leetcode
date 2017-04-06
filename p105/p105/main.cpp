//
//  main.cpp
//  p105
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTree(vector<int>::iterator pl, vector<int>::iterator pr, vector<int>::iterator il, vector<int>::iterator ir) {
        if (il == ir)
            return nullptr;
        auto pos = find(il, ir, *pl);
        TreeNode *root = new TreeNode(*pl);
        root->left = buildTree(pl + 1, (pl + 1) + (pos - il), il, pos);
        root->right = buildTree((pl + 1) + (pos - il), pr, pos + 1, ir);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> preorder = {1, 2};
    vector<int> inorder = {1, 2};
    s.buildTree(preorder, inorder);
    return 0;
}
