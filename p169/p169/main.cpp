//
//  main.cpp
//  p169
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        /*
        int n;
        return majorityElement(nums, 0, (int)nums.size() - 1, n);
        */
        
        /*
        unordered_map<int, int> count;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
            if (++count[nums[i]] > n / 2)
                return nums[i];
        return 0;
        */
        
        /*
        int res = 0;
        int n = (int)nums.size();
        for (int i = 0, mask = 1; i < 32; ++i, mask <<= 1) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (nums[j] & mask)
                    ++count;
                if (count > n / 2) {
                    res |= mask;
                    break;
                }
            }
        }
        return res;
        */
        
        int res = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (res == nums[i])
                ++count;
            else if (count == 0) {
                ++count;
                res = nums[i];
            } else
                --count;
        }
        return res;
    }
    int majorityElement(vector<int>& nums, int left, int right, int& n) {
        if (left > right) {
            n = 0;
            return 0;
        }
        if (left == right) {
            n = 1;
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int x, y;
        int a = majorityElement(nums, left, mid, x);
        int b = majorityElement(nums, mid + 1, right, y);
        if (a == b) {
            n = x + y;
            return a;
        } else {
            if (x < y) {
                n = y - x;
                return b;
            } else if (x > y) {
                n = x - y;
                return a;
            } else {
                n = 0;
                return 0;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {6, 6, 6, 7, 7};
    cout << s.majorityElement(nums) << endl;
    return 0;
}
