/*************************************************************************
  > File Name   : main.cpp
  > Author      : Yunyao Zhang
  > Mail        : aidaizyy@gmail.com
  > Created Time: 2016/10/28 14:16:46
 ************************************************************************/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *p = l1, *q = l2, *r = res;
        while (p != NULL && q != NULL) {
            ListNode node(q->val + q->val);
            r = &node;
            p = p->next;
            q = q->next;
            r = r->next;
        }
        if (p != NULL) {
            ListNode node(p->val);
            r = &node;
            p = p->next;
            r = r->next;
        }
        if (q != NULL) {
            ListNode node(q->val);
            r = &node;
            q = q->next;
            r = r->next;
        }
        if (res == NULL)
            return res;
        ListNode *rev, *tmp1, *tmp2;
        r = res;
        tmp1 = r->next;
        r->next = NULL;
        while (tmp1 != NULL) {
            tmp2 = tmp1->next;
            tmp1->next = r;
            r = tmp1;
            tmp1 = tmp2;
        }
        rev = r;
        r = rev;
        while (r != NULL) {
            if (r->val >= 10) {
                if (r->next != NULL) {
                    r->val -= 10;
                    ++r->next->val;
                } else {
                    ListNode node(1);
                    r->next = &node;
                }
            }
            r = r->next;
        }
        r = rev;
        tmp1 = r->next;
        r->next = NULL;
        while (tmp1 != NULL) {
            tmp2 = tmp1->next;
            tmp1->next = r;
            r = tmp1;
            tmp1 = tmp2;
        }
        res = r;
        return res;
    }
};

int main(){
    Solution s;
    ListNode *l1, *l2;
    ListNode node1(2);
    ListNode node2(4);
    ListNode node3(3);
    ListNode node4(5);
    ListNode node5(6);
    ListNode node6(4);
    l1 = &node1;
    l1->next = &node2;
    l1->next->next = &node3;
    l2 = &node4;
    l2->next = &node5;
    l2->next->next = &node6;
    ListNode *res = s.addTwoNumbers(l1, l2);
    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}



