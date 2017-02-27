//
//  main.cpp
//  p7
//
//  Created by 张云尧 on 2017/2/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

unsigned int a = 0;
int MAX = (~a)/2;
int MAXFLAG = MAX/10;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int flag = 1;
        if (x < 0) {
            flag = -1;
            x *= flag;
        }
        while (x > 0) {
            if (res > MAXFLAG)
                return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        res *= flag;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.reverse(1534236469) << std::endl;
    return 0;
}
