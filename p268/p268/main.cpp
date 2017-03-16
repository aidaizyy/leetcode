//
//  main.cpp
//  p268
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /*
         //26ms
         int sum = nums.size() * (nums.size() + 1) / 2;
         for (int num : nums)
         sum -= num;
         return sum;
         */
        
        //23ms
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= i;
            res ^= nums[i];
        }
        res ^= nums.size();
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
