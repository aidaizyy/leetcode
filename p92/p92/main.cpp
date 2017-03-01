//
//  main.cpp
//  p92
//
//  Created by 张云尧 on 2017/3/2.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return head;
        ListNode* node = head;
        for (int i=0; i<m-2; ++i)
            node = node->next;
        ListNode* prepare = node;
        ListNode* start = prepare->next;
        if (m == 1)
            start = prepare;
        ListNode* prev = start;
        ListNode* next = start->next;
        start->next = nullptr;
        node = next;
        for (int i=m; i<n; ++i) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        start->next = node;
        if (m == 1)
            return prev;
        prepare->next = prev;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode* node = new ListNode(3);
    node->next = new ListNode(5);
    s.reverseBetween(node, 1, 2);
    return 0;
}
