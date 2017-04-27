//
//  main.cpp
//  p164
//
//  Created by 张云尧 on 2017/4/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        /*
        set<int> myset;
        for (int num : nums)
            myset.insert(num);
        int res = 0;
        set<int>::iterator it = myset.begin();
        while (it != myset.end()) {
            int val = *it;
            ++it;
            if (it == myset.end())
                break;
            res = max(res, abs(*it - val));
        }
        return res;
        */
        
        if (nums.size() <= 1)
            return 0;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int num : nums) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }
        int len = ceil((double)(maximum - minimum) / (nums.size() - 1));
        if (len == 0)
            return 0;
        vector<int> mini(ceil((double)(maximum - minimum + 1) / len), INT_MAX);
        vector<int> maxi(ceil((double)(maximum - minimum + 1) / len), INT_MIN);
        for (int num : nums) {
            int idx = (num - minimum) / len;
            mini[idx] = min(mini[idx], num);
            maxi[idx] = max(maxi[idx], num);
        }
        int res = 0;
        int prev = 0;
        for (int i = 1; i < mini.size(); ++i) {
            if (mini[i] == INT_MAX)
                continue;
            res = max(res, mini[i] - maxi[prev]);
            prev = i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
