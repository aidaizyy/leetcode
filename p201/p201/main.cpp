//
//  main.cpp
//  p201
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int l = n - m;
        int base = 1;
        while (l != 0) {
            l >>= 1;
            base <<= 1;
        }
        return m & n & ~(base - 1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.rangeBitwiseAnd(0, 1);
    return 0;
}
