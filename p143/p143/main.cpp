//
//  main.cpp
//  p143
//
//  Created by 张云尧 on 2017/4/26.
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = nullptr;
        ListNode *prev, *next;
        next = node->next;
        node->next = nullptr;
        prev = node;
        node = next;
        while (node != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        node = head;
        while (prev != nullptr) {
            next = node->next;
            node->next = prev;
            node = next;
            next = prev->next;
            prev->next = node;
            prev = next;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
