//
//  main.cpp
//  p160
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
        /*
        ListNode* node = headB;
        while (node->next != nullptr)
            node = node->next;
        node->next = headB;
        ListNode* slow = headA;
        ListNode* fast = headA;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        };
        if (fast == nullptr || fast->next == nullptr) {
            node->next = nullptr;
            return nullptr;
        }
        fast = headA;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        node->next = nullptr;
        return fast;
        */
        
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        while (nodeA != nodeB) {
            if (nodeA == nullptr)
                nodeA = headB;
            else
                nodeA = nodeA->next;
            if (nodeB == nullptr)
                nodeB = headA;
            else
                nodeB = nodeB->next;
        }
        return nodeA;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
