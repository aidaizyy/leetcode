//
//  main.cpp
//  p31
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        vector<int>::reverse_iterator it1 = nums.rbegin() + 1;
        vector<int>::reverse_iterator it2 = nums.rbegin();
        while (it1 != nums.rend()) {
            if (*it1 < *(it1-1))
                break;
            ++it1;
        }
        if (it1 == nums.rend()) {
            reverse(nums.rbegin(), nums.rend());
            return ;
        }
        while (*it2 <= *it1)
            ++it2;
        swap(*it1, *it2);
        reverse(nums.rbegin(), it1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 3, 2};
    s.nextPermutation(nums);
    return 0;
}
