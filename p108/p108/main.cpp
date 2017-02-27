//
//  main.cpp
//  p108
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = (int)nums.size();
        int level = 0;
        for (int i=1; ; ++i) {
            if (size >= (i-1) * (i-1) && size <= i * i) {
                level = i;
                break;
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
