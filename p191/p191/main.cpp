//
//  main.cpp
//  p191
//
//  Created by 张云尧 on 2017/4/7.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        /*
         int res = 0;
         while (n) {
         res += n % 2;
         n /= 2;
         }
         return res;
         */
        
        int res = 0;
        while (n) {
            n &= n - 1;
            ++res;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
