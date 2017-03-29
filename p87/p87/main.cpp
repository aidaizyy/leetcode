//
//  main.cpp
//  p87
//
//  Created by 张云尧 on 2017/3/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;
        int n = (int)s1.size();
        vector<int> count(26, 0);
        for (char ch : s1)
            ++count[ch - 'a'];
        for (char ch : s2)
            --count[ch - 'a'];
        for (int i : count)
            if (i != 0)
                return false;
        for (int i = 1; i < n; ++i)
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))))
                return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
