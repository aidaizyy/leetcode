//
//  main.cpp
//  p459
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = (int)s.size();
        int *next = new int[size+1];
        next[0] = 0;
        next[1] = 0;
        int k = 0;
        for (int i=1; i<size; ++i) {
            while (k > 0 && s[k] != s[i])
                k = next[k];
            if (s[k] == s[i])
                ++k;
            next[i+1] = k;
        }
        if (next[size] != 0 && next[size] % (size - next[size]) == 0)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.repeatedSubstringPattern("abac") << endl;
    return 0;
}
