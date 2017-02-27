//
//  main.cpp
//  p83
//
//  Created by 张云尧 on 2017/2/27.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* prev = head;
        ListNode* node = head;
        while (node->next != nullptr) {
            node = node->next;
            if (node->val == prev->val) {
                prev->next = node->next;
            } else {
                prev = node;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
