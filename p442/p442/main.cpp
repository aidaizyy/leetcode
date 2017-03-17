//
//  main.cpp
//  p442
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0)
                nums[val] *= -1;
            else if (nums[val] < 0)
                res.push_back(val + 1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
