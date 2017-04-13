//
//  main.cpp
//  p117
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
            return ;
        TreeLinkNode* node;
        TreeLinkNode* next = root;
        TreeLinkNode* prev;
        while (next != nullptr) {
            node = next;
            next = nullptr;
            prev = nullptr;
            while (node != nullptr) {
                if (node->left != nullptr) {
                    if (prev != nullptr)
                        prev->next = node->left;
                    else
                        next = node->left;
                    prev = node->left;
                }
                if (node->right != nullptr) {
                    if (prev != nullptr)
                        prev->next = node->right;
                    else
                        next = node->right;
                    prev = node->right;
                }
                node = node->next;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
