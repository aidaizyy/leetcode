//
//  main.cpp
//  p1
//
//  Created by 张云尧 on 2017/2/18.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // 6ms
        vector<int> tmp = nums;
        vector<int> res;
        sort(tmp.begin(), tmp.end());
        int size = (int)tmp.size();
        bool flag = false;
        int value1 = 0, value2 = 0;
        for (int i=0; i<size-1; ++i) {
            if (flag)
                break;
            int left = i + 1;
            int right = size - 1;
            while (left <= right) {
                int j = (left + right) / 2;
                if (tmp[i] + tmp[j] == target) {
                    value1 = tmp[i];
                    value2 = tmp[j];
                    flag = true;
                    break;
                } else if (tmp[i] + tmp[j] < target) {
                    left = j + 1;
                } else {
                    right = j - 1;
                }
            }
        }
        for (int i=0; i<size; ++i) {
            if (nums[i] == value1 || nums[i] == value2) {
                res.push_back(i);
                if (res.size() == 2)
                    break;
            }
        }
        return res;
        
        /*
         // 9ms
         vector<int> res;
         map<int, int> mymap;
         int size = (int)nums.size();
         for (int i=0; i<size; ++i)
             mymap.insert(pair<int, int>(nums[i], i));
         for (int i=0; i<size; ++i) {
             int next = target - nums[i];
             if (mymap.count(next) == 1 && mymap[next] != i) {
                 res.push_back(i);
                 res.push_back(mymap[next]);
                 break;
             }
         }
         return res;
         */
        /*
         // 209ms
         vector<int> res;
         vector<int>::size_type size = nums.size();
         for (int i=0; i<size; ++i) {
             for (int j=i+1; j<size; ++j) {
                 if (target == nums[i] + nums[j]) {
                     res.push_back(j);
                     res.push_back(i);
                 }
             }
         }
         return res;
         */
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = { 2, 7, 11, 15 };
    vector<int> res = s.twoSum(nums, 9);
    return 0;
}
