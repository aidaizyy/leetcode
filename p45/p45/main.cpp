//
//  main.cpp
//  p45
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int pos = 0;
        while (pos + nums[pos] < nums.size() - 1) {
            int max = nums[pos];
            for (int i = 1; i < nums[pos]; ++i) {
                if (i + nums[pos+i] >= max + nums[pos+max] && nums[pos+i] != 0)
                    max = i;
            }
            pos += max;
            ++res;
        }
        if (pos < nums.size() - 1)
            ++res;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
