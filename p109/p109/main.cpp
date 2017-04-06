//
//  main.cpp
//  p109
//
//  Created by 张云尧 on 2017/4/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        prev->next = nullptr;
        if (slow != head)
            root->left = sortedListToBST(head);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
