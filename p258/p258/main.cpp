//
//  main.cpp
//  p258
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        while (1) {
            if (num < 10)
                break;
            int m = 0;
            while (num != 0) {
                int t = num % 10;
                m += t;
                num /= 10;
            }
            num = m;
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
