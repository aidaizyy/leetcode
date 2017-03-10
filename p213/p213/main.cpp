//
//  main.cpp
//  p213
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
        if (size == 1)
            return nums[0];
        vector<int> now(size);
        vector<int> prev(size);
        vector<int> nownf(size);
        vector<int> prevnf(size);
        now[0] = nums[0];
        prev[0] = 0;
        nownf[0] = 0;
        prevnf[0] = 0;
        for (int i=1; i<size; ++i) {
            now[i] = prev[i-1] + nums[i];
            prev[i] = max(now[i-1], prev[i-1]);
            nownf[i] = prevnf[i-1] + nums[i];
            prevnf[i] = max(nownf[i-1], prevnf[i-1]);
        }
        return max(prev[size-1], nownf[size-1]);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {};
    cout << s.rob(nums) << endl;
    return 0;
}
