//
//  main.cpp
//  p198
//
//  Created by 张云尧 on 2017/3/10.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0)
            return 0;
        vector<int> amountnow(size);
        vector<int> amountprev(size);
        amountnow[0] = nums[0];
        amountprev[0] = 0;
        for (int i=1; i<size; ++i) {
            amountnow[i] = amountprev[i-1] + nums[i];
            amountprev[i] = max(amountnow[i-1], amountprev[i-1]);
        }
        return max(amountnow[size-1], amountprev[size-1]);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {};
    cout << s.rob(nums) << endl;
    return 0;
}
