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
    TreeNode* sortedPart(vector<int> nums, int left, int right) {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedPart(nums, left, mid - 1);
        root->right = sortedPart(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedPart(nums, 0, nums.size()-1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
