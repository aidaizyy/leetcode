//
//  main.cpp
//  p138
//
//  Created by 张云尧 on 2017/4/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return nullptr;
        RandomListNode* res;
        unordered_map<int, RandomListNode*> map;
        RandomListNode* now = new RandomListNode(head->label);
        map[head->label] = now;
        res = now;
        while (head != nullptr) {
            if (head->next != nullptr) {
                if (map.find(head->next->label) == map.end()) {
                    now->next = new RandomListNode(head->next->label);
                    map[head->next->label] = now->next;
                } else {
                    now->next = map[head->next->label];
                }
            }
            if (head->random != nullptr) {
                if (map.find(head->random->label) == map.end()) {
                    now->random = new RandomListNode(head->random->label);
                    map[head->random->label] = now->random;
                } else {
                    now->random = map[head->random->label];
                }
            }
            now = now->next;
            head = head->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
