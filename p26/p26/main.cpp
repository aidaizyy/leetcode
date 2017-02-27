//
//  main.cpp
//  p26
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0)
            return 0;
        int pos = 1;
        for (int i=0; i<size-1; ++i) {
            if (nums[i+1] != nums[i]) {
                nums[pos++] = nums[i+1];
            }
        }
        return pos;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 1, 2};
    s.removeDuplicates(nums);
    return 0;
}
