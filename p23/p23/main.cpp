//
//  main.cpp
//  p23
//
//  Created by 张云尧 on 2017/3/10.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    /*
    //459ms nk^2
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        ListNode* root = new ListNode(0);
        ListNode* node = root;
        while (1) {
            int mini = -1;
            int minv = INT_MAX;
            for (int i=0; i<lists.size(); ++i) {
                if (!lists[i])
                    continue;
                if (lists[i]->val < minv) {
                    mini = i;
                    minv = lists[i]->val;
                }
            }
            if (minv == INT_MAX)
                break;
            node->next = lists[mini];
            lists[mini] = lists[mini]->next;
            node = node->next;
        }
        node->next = nullptr;
        return root->next;
    }
    */
    
    /*
    //66ms nklogk
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
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
        return head->next;
    }
    */
    
    //25ms nklogk
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(0);
        ListNode* node = root;
        priority_queue<ListNode*, vector<ListNode*>, cmp> queue;
        for (int i=0; i<lists.size(); ++i) {
            if (lists[i] != nullptr)
                queue.push(lists[i]);
        }
        while (!queue.empty()) {
            node->next = queue.top();
            queue.pop();
            node = node->next;
            if (node->next != nullptr)
                queue.push(node->next);
        }
        return root->next;
    }
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<ListNode*> lists;
    ListNode* root = new ListNode(1);
    lists.push_back(root);
    s.mergeKLists(lists);
    return 0;
}
