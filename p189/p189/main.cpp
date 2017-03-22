//
//  main.cpp
//  p189
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return ;
        int n = (int)nums.size();
        for (int pos = 0; k != 0; n -= k, pos += k) {
            k = k % n;
            for (int i = 0; i < k; ++i) {
                swap(nums[pos + i], nums[pos + n - k + i]);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 2, 3};
    s.rotate(nums, 2);
    return 0;
}
