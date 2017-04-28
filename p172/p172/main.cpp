//
//  main.cpp
//  p172
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int base = 5;
        while (n / base) {
            res += n / base;
            if (base > INT_MAX / 5)
                break;
            base *= 5;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.trailingZeroes(1808548329);
    return 0;
}
