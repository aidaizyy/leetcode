//
//  main.cpp
//  p21
//
//  Created by 张云尧 on 2017/2/22.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (l1 != nullptr)
            node->next = l1;
        if (l2 != nullptr)
            node->next = l2;
        return head->next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
