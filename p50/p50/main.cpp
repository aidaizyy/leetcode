//
//  main.cpp
//  p50
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        double res = 1;
        long long ln = n;
        if (ln < 0) {
            ln = -ln;
            x = 1 / x;
        }
        while (ln != 1) {
            if (ln % 2 == 1)
                res *= x;
            x *= x;
            ln /= 2;
        }
        return res * x;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.myPow(34.00515, -3) << endl;
    return 0;
}
