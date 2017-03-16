//
//  main.cpp
//  p34
//
//  Created by 张云尧 on 2017/3/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        int middle = -1;
        while (left <= right) {
            middle = left + (right - left) / 2;
            if (target == nums[middle])
                break;
            else if (target > nums[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        if (left > right)
            return {-1, -1};
        left = middle;
        while (left >= 0 && nums[left] == target)
            --left;
        right = middle;
        while (right < nums.size() && nums[right] == target)
            ++right;
        return {left + 1, right - 1};
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
