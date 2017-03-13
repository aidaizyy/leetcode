//
//  main.cpp
//  p75
//
//  Created by 张云尧 on 2017/3/13.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        qsort(nums, 0, (int)nums.size()-1);
    }
    void qsort(vector<int>& nums,int left, int right) {
        if (left >= right)
            return ;
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] > nums[left])
                --j;
            while (i < j && nums[i] <= nums[left])
                ++i;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        qsort(nums, left, i-1);
        qsort(nums, i+1, right);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, 2, 1};
    s.sortColors(nums);
    return 0;
}
