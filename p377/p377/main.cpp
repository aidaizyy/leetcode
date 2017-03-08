//
//  main.cpp
//  p377
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        helper(res, nums, target);
        return res;
    }
    void helper(int& res, vector<int> nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] < target) {
                helper(res, nums, target-nums[i]);
            } else if (nums[i] == target) {
                ++res;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 1, 2};
    s.combinationSum4(nums, 8);
    return 0;
}
