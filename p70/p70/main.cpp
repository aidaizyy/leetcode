//
//  main.cpp
//  p70
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        int res[n+1];
        res[0] = 1;
        res[1] = 1;
        for (int i=2; i<=n; ++i) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.climbStairs(2);
    return 0;
}
