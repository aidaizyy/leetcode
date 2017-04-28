//
//  main.cpp
//  p342
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        
        /*
        if (num <= 0)
            return false;
        while (num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
        */
        
        if (num <= 0)
            return false;
        if ((num & (num - 1)) != 0)
            return false;
        return (num & 0x55555555) != 0;
        //return (num - 1) % 3 == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isPowerOfFour(6);
    return 0;
}
