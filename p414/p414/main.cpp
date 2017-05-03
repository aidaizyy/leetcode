//
//  main.cpp
//  p414
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        /*
        long long first = (long long)INT_MIN - 1;
        long long second = (long long)INT_MIN - 1;
        long long third = (long long)INT_MIN - 1;
        for (int num : nums) {
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num < first && num > second) {
                third = second;
                second = num;
            } else if (num < second && num > third) {
                third = num;
            }
        }
        return third == (long long)INT_MIN - 1 ? (int)first : (int)third;
        */
        
        set<int> myset;
        for (int num : nums) {
            myset.insert(num);
            if (myset.size() > 3)
                myset.erase(myset.begin());
        }
        return myset.size() == 3 ? *myset.begin() : *myset.rbegin();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 2, 1};
    s.thirdMax(nums);
    return 0;
}
