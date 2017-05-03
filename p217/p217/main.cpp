//
//  main.cpp
//  p217
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for (int num : nums) {
            if (myset.find(num) != myset.end())
                return true;
            myset.insert(num);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
