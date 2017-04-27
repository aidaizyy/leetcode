//
//  main.cpp
//  p171
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    class Solution {
    public:
        int titleToNumber(string s) {
            int res = 0;
            constexpr int radix = 26;
            constexpr char base = 'A';
            for (char c : s) {
                res *= radix;
                res += c - base;
                ++res;
            }
            return res;
        }
    };
    return 0;
}
