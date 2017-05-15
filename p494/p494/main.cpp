//
//  main.cpp
//  p494
//
//  Created by 张云尧 on 2017/5/15.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /*
    //442ms
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        if (nums.size() == 0)
            return res;
        findTargetSumWays(res, nums, S, 0, 0);
        return res;
    }
    void findTargetSumWays(int& res, vector<int>& nums, int S, int pos, int prev) {
        if (pos == nums.size()) {
            if (prev == S)
                ++res;
            return ;
        }
        findTargetSumWays(res, nums, S, pos + 1, prev + nums[pos]);
        findTargetSumWays(res, nums, S, pos + 1, prev - nums[pos]);
    }
    */
    
    //3ms
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum < S)
            return 0;
        sum += S;
        if (sum & 1)
            return 0;
        sum /= 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int i = sum; i >= num; --i)
                dp[i] += dp[i - num];
        return dp[sum];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 7, 9, 981};
    s.findTargetSumWays(nums, 3);
    return 0;
}
