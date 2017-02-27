//
//  main.cpp
//  p13
//
//  Created by 张云尧 on 2017/2/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int i = 0;
        s += "QQ";
        while (s[i] == 'M') {
            res += 1000;
            ++i;
        }
        if (s[i+1] == 'M') {
            res += 900;
            i += 2;
        } else if (s[i+1] == 'D') {
            res += 400;
            i += 2;
        } else if (s[i] == 'D') {
            res += 500;
            ++i;
        }
        while (s[i] == 'C') {
            res += 100;
            ++i;
        }
        if (s[i+1] == 'C') {
            res += 90;
            i += 2;
        } else if (s[i+1] == 'L') {
            res += 40;
            i += 2;
        } else if (s[i] == 'L') {
            res += 50;
            ++i;
        }
        while (s[i] == 'X') {
            res += 10;
            ++i;
        }
        if (s[i+1] == 'X') {
            res += 9;
            i += 2;
        } else if (s[i+1] == 'V') {
            res += 4;
            i += 2;
        } else if (s[i] == 'V') {
            res += 5;
            ++i;
        }
        while (s[i] == 'I') {
            res += 1;
            ++i;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.romanToInt("MDCCCLXXXIV") << endl;
    return 0;
}
