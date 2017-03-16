//
//  main.cpp
//  p136
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
