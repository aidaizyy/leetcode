//
//  main.cpp
//  p62
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long res = 1;
        int s = m + n - 2;
        int t = std::min(m - 1, n - 1);
        for (int i = 0; i < t; ++i)
            res *= s - i;
        for (int i = 0; i < t; ++i)
            res /= t - i;
        return (int)res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
