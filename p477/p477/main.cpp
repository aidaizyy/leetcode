//
//  main.cpp
//  p477
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int zero = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] % 2 == 0)
                    ++zero;
                nums[i] /= 2;
            }
            res += zero * (nums.size() - zero);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {4, 12, 2};
    s.totalHammingDistance(nums);
    return 0;
}
