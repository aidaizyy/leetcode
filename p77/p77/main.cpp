//
//  main.cpp
//  p77
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /*
    //142ms
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> group;
        helper(res, group, 0, n, k);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> group, int last, int n, int k) {
        if (k == 0) {
            res.push_back(group);
            return ;
        }
        for (int num=last+1; num<=n; ++num) {
            if (k > 0) {
                group.push_back(num);
                helper(res, group, num, n, k-1);
                group.pop_back();
            }
        }
    }
    */
    
    //72ms
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> group(k, 0);
        int i = 0;
        while (i >= 0) {
            group[i]++;
            if (group[i] > n)
                --i;
            else if (i == k - 1)
                res.push_back(group);
            else {
                ++i;
                group[i] = group[i - 1];
            }
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    s.combine(4, 2);
    return 0;
}
