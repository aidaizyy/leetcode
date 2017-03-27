//
//  main.cpp
//  p82
//
//  Created by 张云尧 on 2017/3/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* node = new ListNode(0);
        node->next = head;
        head = node;
        node = head->next;
        ListNode* prev = head;
        bool flag = false;
        while (node != nullptr) {
            if (node->next != nullptr && node->val == node->next->val) {
                node->next = node->next->next;
                flag = true;
            } else if (flag) {
                prev->next = node->next;
                node = prev->next;
                flag = false;
            } else {
                prev = node;
                node = node->next;
            }
        }
        return head->next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
