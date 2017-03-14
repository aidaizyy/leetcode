//
//  main.cpp
//  p25
//
//  Created by 张云尧 on 2017/3/14.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr)
            return head;
        ListNode* node = head;
        for (int i=0; i<k-1; ++i) {
            node = node->next;
            if (node == nullptr)
                return head;
        }
        ListNode* later = node->next;
        node->next = nullptr;
        node = head;
        ListNode *prev, *next;
        next = node->next;
        node->next = reverseKGroup(later, k);
        prev = node;
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
