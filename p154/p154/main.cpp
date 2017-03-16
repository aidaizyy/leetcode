//
//  main.cpp
//  p154
//
//  Created by 张云尧 on 2017/3/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> pivot;
        pivot.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] > nums[i])
                pivot.push_back(nums[i]);
        }
        int minv = pivot[0];
        for (int i = 1; i < pivot.size(); ++i) {
            minv = min(minv, pivot[i]);
        }
        return minv;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
