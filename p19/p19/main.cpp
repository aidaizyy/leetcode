//
//  main.cpp
//  p19
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
    /*
    //12ms
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        head = reverseList(head);
        if (n == 1)
            return reverseList(head->next);
        ListNode* node = head;
        for (int i=0; i<n-2; ++i) {
            node = node->next;
        }
        node->next = node->next->next;
        return reverseList(head);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode *prev, *next;
        next = node->next;
        node->next = nullptr;
        prev = head;
        node = next;
        while (next != nullptr) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    */
    
    //6ms
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        ListNode* prev = head;
        for (int i=0; i<n; ++i)
            node = node->next;
        if (node == nullptr)
            return head->next;
        while (node->next != nullptr) {
            node = node->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
