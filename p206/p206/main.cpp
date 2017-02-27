//
//  main.cpp
//  p206
//
//  Created by 张云尧 on 2017/2/21.
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* node = head;
        ListNode* prev = node;
        ListNode* next = node->next;
        node->next = nullptr;
        node = next;
        while (node != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
