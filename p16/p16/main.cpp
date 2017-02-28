//
//  main.cpp
//  p16
//
//  Created by 张云尧 on 2017/2/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        for (int i=0; i<size-2; ++i) {
            if (i != 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                    ++left;
                    while (left < right && nums[left] == nums[left-1])
                        ++left;
                } else if (sum > target) {
                    if (abs(sum - target) < diff) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                    --right;
                    while (left < right && nums[right] == nums[right+1])
                        --right;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 6, 9, 14, 16, 70};
    cout << s.threeSumClosest(nums, 81) << endl;
    return 0;
}
