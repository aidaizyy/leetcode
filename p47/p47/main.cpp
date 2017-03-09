//
//  main.cpp
//  p47
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(res, item, flag, nums);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> item, vector<bool> flag, vector<int> nums) {
        if (item.size() == nums.size()) {
            res.push_back(item);
            return ;
        }
        int last = -1;
        for (int i=0; i<nums.size(); ++i) {
            if (flag[i] == false) {
                if (last != -1) {
                    if (nums[i] == nums[last])
                        continue;
                }
                last = i;
                flag[i] = true;
                item.push_back(nums[i]);
                helper(res, item, flag, nums);
                flag[i] = false;
                item.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1,1,1,2,2,2,3};
    s.permuteUnique(nums);
    return 0;
}
