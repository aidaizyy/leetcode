//
//  main.cpp
//  p203
//
//  Created by 张云尧 on 2017/2/23.
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr)
            return head;
        ListNode* node = head;
        ListNode* prev = node;
        node = node->next;
        while (node != nullptr) {
            if (node->val == val) {
                prev->next = node->next;
            } else {
                prev = prev->next;
            }
            node = node->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
