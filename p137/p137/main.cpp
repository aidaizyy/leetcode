//
//  main.cpp
//  p137
//
//  Created by 张云尧 on 2017/3/18.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int threes = 0;
        for (int num : nums) {
            threes = twos & num;
            twos |= ones & num;
            ones |= num;
            twos ^= threes;
            ones ^= threes;
        }
        return ones;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
