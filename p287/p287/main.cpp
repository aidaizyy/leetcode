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
        //13ms nlogn
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
        */
        
        /*
        //9ms nlogn
        int left = 1;
        int right = nums.size() - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= middle)
                    ++count;
            }
            if (count > middle)
                right = middle;
            else
                left = middle + 1;
        }
        return left;
        */
        
        //9ms n
        if (nums.size() <= 1)
            return -1;
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
