//
//  main.cpp
//  p29
//
//  Created by 张云尧 on 2017/3/14.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long dvd = dividend;
        long long dvs = divisor;
        int sign = 1;
        if (dvd < 0) {
            sign *= -1;
            dvd *= -1;
        }
        if (dvs < 0) {
            sign *= -1;
            dvs *= -1;
        }
        long long res = 0;
        while (dvd >= dvs) {
            long long tmp = dvs;
            long long multiple = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            dvd -= tmp;
            res += multiple;
        }
        return (int)res * sign;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
