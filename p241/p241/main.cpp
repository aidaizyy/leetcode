//
//  main.cpp
//  p241
//
//  Created by 张云尧 on 2017/4/13.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute(input, 0, (int)input.size() - 1);
    }
    vector<int> diffWaysToCompute(string& input, int left, int right) {
        vector<int> res;
        bool flag = false;
        for (int i = left; i <= right; ++i) {
            if (input[i] >= '0' && input[i] <= '9')
                continue;
            flag = true;
            vector<int> l = diffWaysToCompute(input, left, i - 1);
            vector<int> r = diffWaysToCompute(input, i + 1, right);
            for (int j = 0; j < l.size(); ++j) {
                for (int k = 0; k < r.size(); ++k) {
                    res.push_back(calculate(l[j], r[k], input[i]));
                }
            }
        }
        if (!flag) {
            int tmp = 0;
            for (int i = left; i <= right; ++i) {
                tmp *= 10;
                tmp += input[i] - '0';
            }
            res.push_back(tmp);
        }
        return res;
    }
    int calculate(int m, int n, char ch) {
        if (ch == '+')
            return m + n;
        else if (ch == '-')
            return m - n;
        else
            return m * n;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.diffWaysToCompute("2-1-1");
    return 0;
}
