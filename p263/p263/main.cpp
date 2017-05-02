//
//  main.cpp
//  p263
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num % 2 == 0)
            num /= 2;
        while (num % 3 == 0)
            num /= 3;
        while (num % 5 == 0)
            num /= 5;
        return num == 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
