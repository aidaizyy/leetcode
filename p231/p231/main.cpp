//
//  main.cpp
//  p231
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        /*
        if (n <= 0)
            return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
        */
        
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
