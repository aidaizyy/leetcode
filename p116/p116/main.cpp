//
//  main.cpp
//  p116
//
//  Created by 张云尧 on 2017/4/13.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr) {
            root->left->next = root->right;
            if (root->next != nullptr)
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
