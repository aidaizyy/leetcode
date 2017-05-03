//
//  main.cpp
//  p220
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0)
            return false;
        set<int> myset;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                myset.erase(nums[i - k - 1]);
            auto it = myset.lower_bound((int)max((long long)INT_MIN, (long long)nums[i] - t));
            auto it2 = myset.upper_bound((int)min((long long)INT_MAX, (long long)nums[i] + t));
            if (it != it2)
                return true;
            myset.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, INT_MAX};
    s.containsNearbyAlmostDuplicate(nums, 1, INT_MAX);
    return 0;
}
