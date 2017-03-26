//
//  main.cpp
//  p80
//
//  Created by 张云尧 on 2017/3/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int size = (int)nums.size();
        int pos = 1;
        for (int i = 0; i < size - 2; ++i) {
            if (nums[i + 1] != nums[i] || nums[i + 2] != nums[i]) {
                nums[pos++] = nums[i + 1];
            }
        }
        if (size >= 2 && nums[size - 2] != nums[size - 1])
            nums[pos++] = nums[size - 1];
        return pos;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1};
    s.removeDuplicates(nums);
    return 0;
}
