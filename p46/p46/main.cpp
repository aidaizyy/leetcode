//
//  main.cpp
//  p46
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        vector<bool> flag(nums.size(), false);
        helper(res, item, flag, nums);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> item, vector<bool> flag, vector<int> nums) {
        if (item.size() == nums.size()) {
            res.push_back(item);
            return ;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (flag[i] == false) {
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
    vector<int> nums = {1, 2, 3};
    s.permute(nums);
    return 0;
}
