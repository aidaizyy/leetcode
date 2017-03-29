//
//  main.cpp
//  p89
//
//  Created by 张云尧 on 2017/3/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int x = 0;
        res.push_back(x);
        helper(res, x, n);
        return res;
    }
    void helper(vector<int>& res, int& x, int n) {
        for (int i = 0; i < n; ++i) {
            x ^= (1 << i);
            res.push_back(x);
            helper(res, x, i);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.grayCode(5);
    return 0;
}
