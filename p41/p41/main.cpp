//
//  main.cpp
//  p41
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
