//
//  main.cpp
//  p328
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* list1 = new ListNode(0);
        ListNode* list2 = new ListNode(0);
        ListNode* node[2];
        node[0] = list1;
        node[1] = list2;
        int r = 0;
        while (head != nullptr) {
            node[r]->next = head;
            node[r] = node[r]->next;
            head = head->next;
            r ^= 1;
        }
        node[0]->next = list2->next;
        node[1]->next = nullptr;
        return list1->next;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
