//
//  main.cpp
//  p445
//
//  Created by 张云尧 on 2017/2/28.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* n1 = l1->next;
        l1->next = nullptr;
        l1 = n1;
        while (l1) {
            n1 = l1->next;
            l1->next = p1;
            p1 = l1;
            l1 = n1;
        }
        l1 = p1;
        
        ListNode* p2 = l2;
        ListNode* n2 = l2->next;
        l2->next = nullptr;
        l2 = n2;
        while (l2) {
            n2 = l2->next;
            l2->next = p2;
            p2 = l2;
            l2 = n2;
        }
        l2 = p2;
        
        ListNode* res = new ListNode(0);
        ListNode* l3 = res;
        int next = 0;
        while (l1 && l2) {
            l3->next = new ListNode(l1->val + l2->val + next);
            l3 = l3->next;
            if (l3->val >= 10) {
                l3->val -= 10;
                next = 1;
            } else
                next = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            l3->next = new ListNode(l1->val + next);
            l3 = l3->next;
            if (l3->val >= 10) {
                l3->val -= 10;
                next = 1;
            } else
                next = 0;
            l1 = l1->next;
        }
        while (l2) {
            l3->next = new ListNode(l2->val + next);
            l3 = l3->next;
            if (l3->val >= 10) {
                l3->val -= 10;
                next = 1;
            } else
                next = 0;
            l2 = l2->next;
        }
        if (next == 1) {
            l3->next = new ListNode(1);
        }
        
        l3 = res->next;
        ListNode* p3 = l3;
        ListNode* n3 = l3->next;
        l3->next = nullptr;
        l3 = n3;
        while (l3) {
            n3 = l3->next;
            l3->next = p3;
            p3 = l3;
            l3 = n3;
        }
        return p3;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    s.addTwoNumbers(l1, l2);
    return 0;
}
