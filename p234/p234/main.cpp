//
//  main.cpp
//  p234
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }
        slow = reverList(slow);
        fast = head;
        while (slow != nullptr) {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    ListNode* reverList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* node = head;
        ListNode* prev = head;
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    std::cout << s.isPalindrome(head) << std::endl;
    return 0;
}
