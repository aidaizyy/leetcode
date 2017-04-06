//
//  main.cpp
//  p257
//
//  Created by 张云尧 on 2017/4/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str;
        binaryTreePaths(root, str, res);
        return res;
    }
    void binaryTreePaths(TreeNode* node, string& str, vector<string>& res) {
        if (node == nullptr)
            return ;
        string prev = str;
        str += to_string(node->val);
        str += "->";
        if (node->left == nullptr && node->right == nullptr) {
            res.push_back(str.substr(0, str.size() - 2));
        }
        binaryTreePaths(node->left, str, res);
        binaryTreePaths(node->right, str, res);
        str = prev;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
