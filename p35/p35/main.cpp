//
//  main.cpp
//  p35
//
//  Created by 张云尧 on 2017/2/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] >= target)
                return i;
        }
        return nums.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
