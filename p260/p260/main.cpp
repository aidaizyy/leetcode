//
//  main.cpp
//  p260
//
//  Created by 张云尧 on 2017/3/18.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num : nums)
            xorsum ^= num;
        xorsum &= -xorsum;
        vector<int> res(2, 0);
        for (int num : nums) {
            if ((num & xorsum) == 0)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
