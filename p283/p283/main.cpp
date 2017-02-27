//
//  main.cpp
//  p283
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = (int)nums.size();
        int pos = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[pos++] = num;
            }
        }
        for (; pos<size; ++pos) {
            nums[pos] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {0, 1, 0};
    s.moveZeroes(nums);
    return 0;
}
