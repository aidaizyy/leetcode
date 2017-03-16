//
//  main.cpp
//  p287
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        /*
        //13ms
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
        */
        
        //9ms
        if (nums.size() > 1) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
