//
//  main.cpp
//  p86
//
//  Created by 张云尧 on 2017/3/29.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* node1 = head1;
        ListNode* node2 = head2;
        while (head != nullptr) {
            if (head->val < x) {
                node1->next = head;
                node1 = node1->next;
            } else {
                node2->next = head;
                node2 = node2->next;
            }
            head = head->next;
        }
        node2->next = nullptr;
        node1->next = head2->next;
        return head1->next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
