//
//  main.cpp
//  p90
//
//  Created by 张云尧 on 2017/3/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> item;
        helper(res, nums, item, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& item, int pos) {
        res.push_back(item);
        int last = nums[pos];
        for (int i = pos; i < nums.size(); ++i) {
            if (i != pos && nums[i] == last)
                continue;
            last = nums[i];
            item.push_back(nums[i]);
            helper(res, nums, item, i + 1);
            item.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 2};
    s.subsetsWithDup(nums);
    return 0;
}
