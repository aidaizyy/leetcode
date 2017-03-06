//
//  main.cpp
//  p152
//
//  Created by 张云尧 on 2017/3/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxnow = nums[0];
        int minnow = nums[0];
        int maxprev = nums[0];
        int minprev = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            maxnow = max(max(maxprev * nums[i], minprev * nums[i]), nums[i]);
            minnow = min(min(maxprev * nums[i], minprev * nums[i]), nums[i]);
            if (res < maxnow)
                res = maxnow;
            maxprev = maxnow;
            minprev = minnow;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {2, -5, -2, -4, 3};
    cout << s.maxProduct(nums) << endl;
    return 0;
}
