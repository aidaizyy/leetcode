//
//  main.cpp
//  p228
//
//  Created by 张云尧 on 2017/5/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        nums.push_back(INT_MAX);
        res.push_back(to_string(nums[0]));
        int begin = nums[0];
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last + 1) {
                if (last != begin) {
                    res.back() += "->";
                    res.back() += to_string(last);
                }
                res.push_back(to_string(nums[i]));
                begin = nums[i];
            }
            last = nums[i];
        }
        res.erase(res.begin() + res.size() - 1);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
