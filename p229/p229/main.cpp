//
//  main.cpp
//  p229
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        /*
        vector<int> res;
        unordered_map<int, int> counts;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i)
            if (++counts[nums[i]] > n / 3)
                if (find(res.begin(), res.end(), nums[i]) == res.end())
                    res.push_back(nums[i]);
        return res;
        */
        
        int res1 = 0, res2 = 0;
        int count1 = 0, count2 = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (res1 == nums[i])
                ++count1;
            else if (res2 == nums[i])
                ++count2;
            else if (count1 == 0) {
                ++count1;
                res1 = nums[i];
            } else if (count2 == 0) {
                ++count2;
                res2 = nums[i];
            } else {
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (res1 == nums[i])
                ++count1;
            else if (res2 == nums[i])
                ++count2;
        }
        vector<int> res;
        if (count1 > n / 3)
            res.push_back(res1);
        if (count2 > n / 3)
            res.push_back(res2);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1};
    s.majorityElement(nums);
    return 0;
}
