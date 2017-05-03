//
//  main.cpp
//  p215
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        /*
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
        */
        
        --k;
        int left = 0;
        int right = (int)nums.size() - 1;
        random_shuffle(nums.begin(), nums.end());
        while (left < right) {
            int l = left + 1;
            int r = right;
            while (l <= r) {
                while (l <= r && nums[r] <= nums[left])
                    --r;
                while (l <= r && nums[l] > nums[left])
                    ++l;
                if (l < r)
                    swap(nums[r], nums[l]);
            }
            swap(nums[r], nums[left]);
            if (r < k)
                left = r + 1;
            else if (r > k)
                right = r - 1;
            else
                break;
        }
        return nums[k - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {5, 2, 4, 1, 3, 6, 0};
    s.findKthLargest(nums, 2);
    return 0;
}
