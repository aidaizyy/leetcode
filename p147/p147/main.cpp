//
//  main.cpp
//  p147
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* sorted = head;
        ListNode* unsorted = head->next;
        while (unsorted != nullptr) {
            if (unsorted->val >= sorted->val) {
                sorted = unsorted;
                unsorted = unsorted->next;
            } else if (unsorted->val < head->val) {
                sorted->next = unsorted->next;
                unsorted->next = head;
                head = unsorted;
                unsorted = sorted->next;
            } else {
                ListNode* node = head;
                while (unsorted->val >= node->next->val)
                    node = node->next;
                sorted->next = unsorted->next;
                unsorted->next = node->next;
                node->next = unsorted;
                unsorted = sorted->next;
            }
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    s.insertionSortList(head);
    return 0;
}
