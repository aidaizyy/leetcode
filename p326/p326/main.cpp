//
//  main.cpp
//  p326
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        /*
        if (n <= 0)
            return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
        */
        
        if (n <= 0)
            return false;
        double m = log10(n) / log10(3);
        return (int)m - m == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
