//
//  main.cpp
//  p238
//
//  Created by 张云尧 on 2017/3/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> res(size, 1);
        for (int i=1; i<size; ++i)
            res[i] = res[i-1] * nums[i-1];
        int tmp = 1;
        for (int i=size-2; i>=0; --i) {
            tmp *= nums[i+1];
            res[i] *= tmp;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 0};
    s.productExceptSelf(nums);
    return 0;
}
