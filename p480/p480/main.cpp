//
//  main.cpp
//  p480
//
//  Created by 张云尧 on 2017/5/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        ret.push_back(((double)*mid + *prev(mid, 1 - k % 2)) / 2);
        for (int i = k; i < nums.size(); ++i) {
            window.insert(nums[i]);
            if (nums[i] < *mid)
                --mid;
            if (nums[i - k] <= *mid)
                ++mid;
            window.erase(window.lower_bound(nums[i - k]));
            ret.push_back(((double)*mid + *prev(mid, 1 - k % 2)) / 2.0);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
