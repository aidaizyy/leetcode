//
//  main.cpp
//  p179
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool cmp(const string& s, const string& t) {
    return s + t > t + s;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstrs;
        for (int num : nums)
            numstrs.push_back(to_string(num));
        sort(numstrs.begin(), numstrs.end(), cmp);
        if (numstrs.size() == 0 || numstrs[0] == "0")
            return "0";
        string res = "";
        for (string str : numstrs) {
            res += str;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {121,12};
    s.largestNumber(nums);
    return 0;
}
