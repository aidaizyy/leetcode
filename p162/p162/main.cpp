//
//  main.cpp
//  p162
//
//  Created by 张云尧 on 2017/4/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        nums.push_back(INT_MIN);
        int left = 0;
        int right = (int)nums.size() - 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid == 0)
                return nums[mid] < nums[mid + 1] ? mid + 1 : mid;
            if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
                return mid;
            if (nums[mid - 1] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
