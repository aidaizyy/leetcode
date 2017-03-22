//
//  main.cpp
//  p61
//
//  Created by 张云尧 on 2017/3/22.
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        /*
        //9ms
        int count = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr) {
            slow = slow->next;
            ++count;
        }
        if (count == 0)
            return head;
        k %= count;
        if (k == 0)
            return head;
        for (int i = 0; i < k ; ++i) {
            fast = fast->next;
        }
        slow = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
        */
        
        //9ms
        if (head == nullptr)
            return head;
        int count = 1;
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
            ++count;
        }
        k %= count;
        node->next = head;
        for (int i = 0; i < count-k; ++i)
            node = node->next;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
