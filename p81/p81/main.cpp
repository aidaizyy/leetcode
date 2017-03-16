//
//  main.cpp
//  p81
//
//  Created by 张云尧 on 2017/3/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        vector<int> pivot;
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1])
                pivot.push_back(i);
        }
        pivot.push_back((int)nums.size() - 1);
        int left = 0;
        int right = pivot[0];
        for (int i = 1; i < pivot.size(); ++i) {
            if (target >= nums[pivot[i-1]+1] && target <= nums[pivot[i]]) {
                left = pivot[i-1] + 1;
                right = pivot[i];
                break;
            }
        }
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (target == nums[middle])
                return true;
            else if (target > nums[middle])
                left = middle + 1;
            else
                right = middle - 1;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
