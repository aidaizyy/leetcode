//
//  main.cpp
//  p209
//
//  Created by 张云尧 on 2017/3/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = (int)nums.size() + 1;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= s) {
                if (right - left + 1 < len)
                    len = right - left + 1;
                sum -= nums[left++];
            }
            ++right;
        }
        return len % (nums.size() + 1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
