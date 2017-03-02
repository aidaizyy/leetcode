//
//  main.cpp
//  p8
//
//  Created by 张云尧 on 2017/3/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        while (str[i] == ' ') ++i;
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            ++i;
        } else if (str[i] == '+') {
            ++i;
        }
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            if (res > INT_MAX / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            res *= 10;
            if (sign == 1 && res > INT_MAX - (str[i] - '0'))
                return INT_MAX;
            else if (sign == -1 && res - 1 > INT_MAX - (str[i] - '0'))
                return INT_MIN;
            res += str[i] - '0';
            ++i;
        }
        res *= sign;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.myAtoi("-2147483649") << endl;
    return 0;
}
