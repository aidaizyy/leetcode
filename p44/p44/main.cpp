//
//  main.cpp
//  p44
//
//  Created by 张云尧 on 2017/3/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string::iterator its = s.begin();
        string::iterator itp = p.begin();
        bool star = false;
        auto j = its;
        auto k = itp;
        while (*j != '\0') {
            if (*k == '*') {
                star = true;
                while (*k == '*')
                    ++k;
                if (*k == '\0')
                    return true;
                its = j;
                itp = k;
            } else if (*j == *k || *k == '?') {
                ++j;
                ++k;
            } else {
                if (!star)
                    return false;
                ++its;
                j = its;
                k = itp;
            }
        }
        while (*k == '*')
            ++k;
        return *k == '\0';
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
    return 0;
}
