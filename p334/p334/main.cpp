//
//  main.cpp
//  p334
//
//  Created by 张云尧 on 2017/5/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
                if (res.size() >= 3)
                    return true;
            } else
                *it = nums[i];
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s
    return 0;
}
