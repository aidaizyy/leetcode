//
//  main.cpp
//  p148
//
//  Created by 张云尧 on 2017/3/13.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        head = sortList(head);
        slow = sortList(slow);
        return merge(head, slow);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* list = new ListNode(0);
        ListNode* node = list;
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
        return list->next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(5);
    s.sortList(head);
    return 0;
}
