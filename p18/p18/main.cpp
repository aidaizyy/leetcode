//
//  main.cpp
//  p18
//
//  Created by 张云尧 on 2017/2/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = (int)nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-3; ++i) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            for (int j=i+1; j<size-2; ++j) {
                if (j != i+1 && nums[j] == nums[j-1])
                    continue;
                int left = j + 1;
                int right = size - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum < target) {
                        ++left;
                        while (left < right && nums[left] == nums[left-1])
                            ++left;
                    } else if (sum > target) {
                        --right;
                        while (left < right && nums[right] == nums[right+1])
                            --right;
                    } else {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left-1])
                            ++left;
                        while (left < right && nums[right] == nums[right+1])
                            --right;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
