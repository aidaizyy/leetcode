//
//  main.cpp
//  p219
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        /*
        //42ms
        multimap<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i) {
            auto its = mymap.equal_range(nums[i]);
            for (auto it = its.first; it != its.second; ++it) {
                if (abs(it->second - i) <= k)
                    return true;
            }
            mymap.insert(make_pair(nums[i], i));
        }
        return false;
        */
        
        //26ms
        unordered_set<int> myset;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                myset.erase(nums[i - k - 1]);
            if (myset.find(nums[i]) != myset.end())
                return true;
            myset.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
