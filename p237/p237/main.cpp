//
//  main.cpp
//  p237
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
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
