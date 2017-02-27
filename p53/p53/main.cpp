//
//  main.cpp
//  p53
//
//  Created by 张云尧 on 2017/2/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = nums[0];
        for (int num : nums) {
            sum += num;
            if (res < sum)
                res = sum;
            if (sum < 0)
                sum = 0;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {-1};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}
