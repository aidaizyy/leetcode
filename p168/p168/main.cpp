//
//  main.cpp
//  p168
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        constexpr int radix = 26;
        constexpr char base = 'A';
        while (n != 0) {
            --n;
            int c = n % radix;
            res += base + c;
            n /= radix;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
