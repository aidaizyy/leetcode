//
//  main.cpp
//  p24
//
//  Created by 张云尧 on 2017/3/13.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* tmp = head;
        head = head->next;
        tmp->next = head->next;
        head->next = tmp;
        ListNode* node = head->next;
        while (node->next != nullptr && node->next->next != nullptr) {
            ListNode* tmp = node->next;
            node->next = node->next->next;
            tmp->next = node->next->next;
            node->next->next = tmp;
            node = node->next->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
