//
//  main.cpp
//  p55
//
//  Created by 张云尧 on 2017/3/18.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        while (nums[pos] != 0 && pos + nums[pos] < nums.size() - 1) {
            int max = nums[pos];
            for (int i = 1; i < nums[pos]; ++i) {
                if (i + nums[pos+i] >= max + nums[pos+max] && nums[pos+i] != 0)
                    max = i;
            }
            pos += max;
        }
        if (pos + nums[pos] >= nums.size() - 1)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {2, 5, 0, 0};
    cout << s.canJump(nums) << endl;
    return 0;
}
