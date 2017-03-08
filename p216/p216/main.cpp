//
//  main.cpp
//  p216
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> group;
        helper(res, group, 0, k, n);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> group, int last, int k, int n) {
        if (k == 0 && n == 0)
            res.push_back(group);
        if (k == 0)
            return ;
        for (int num=last+1; num<=9; ++num) {
            if (k >= 1 && num <= n) {
                group.push_back(num);
                helper(res, group, num, k-1, n-num);
                group.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.combinationSum3(3, 7);
    return 0;
}
