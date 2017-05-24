//
//  main.cpp
//  p300
//
//  Created by 张云尧 on 2017/5/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        /*
        //O(n^2)
        vector<int> dp(nums.size(), 1);
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret = max(ret, dp[i]);
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[i])
                    dp[j] = max(dp[j], dp[i] + 1);
                ret = max(ret, dp[j]);
            }
        }
        return ret;
        */
        
        //O(nlogn)
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return (int)res.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}
