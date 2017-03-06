//
//  main.cpp
//  p10
//
//  Created by 张云尧 on 2017/3/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatchHelper(string::iterator s, string::iterator p) {
        if (*p == '\0')
            return *s == '\0';
        if (*(p + 1) != '*') {
            if (*s == *p || (*p == '.' && *s != '\0'))
                return isMatchHelper(s+1, p+1);
            else
                return false;
        } else {
            while (*s == *p || (*p == '.' && *s != '\0')) {
                if (isMatchHelper(s, p+2))
                    return true;
                ++s;
            }
            return isMatchHelper(s, p+2);
        }
    }
    bool isMatch(string s, string p) {
        //return isMatchHelper(s.begin(), p.begin());
        string::iterator its = s.begin();
        string::iterator itp = p.begin();
        bool star = false;
        auto j = its;
        auto k = itp;
        while (*j != '\0') {
            if (*(k+1) == '*') {
                star = true;
                ++its;
                j = its;
                k = itp
            } else if (*j == *k || *k == '.') {
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
        return *k == '\0';
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isMatch("aaab", "a*b") << endl; //1
    cout << s.isMatch("b", "a*b") << endl; // 1
    cout << s.isMatch("aaab", "a*ab") << endl;// 1
    cout << s.isMatch("cb", "a*b") << endl;
    cout << s.isMatch("aa", ".*") << endl;
    cout << s.isMatch("a", ".*") << endl;
    cout << s.isMatch("", ".*") << endl;
    cout << s.isMatch("b", "a.*") << endl;
    cout << s.isMatch("aab", ".*b") << endl;
    cout << s.isMatch("aabc", ".*bc") << endl;
    cout << s.isMatch("aaa", "ab*a*c*a") << endl;
    return 0;
}
