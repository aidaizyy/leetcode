//
//  main.cpp
//  p28
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int *next = new int[needle.size() + 1];
        next[0] = 0;
        next[1] = 0;
        int k = 0;
        for (int i=1; i<needle.size(); ++i) {
            while (k > 0 && needle[k] != needle[i])
                k = next[k];
            if (needle[k] == needle[i])
                ++k;
            next[i+1] = k;
        }
        k = 0;
        for (int i=0; i<haystack.size(); ++i) {
            while (k > 0 && haystack[i] != needle[k])
                k = next[k];
            if (haystack[i] == needle[k])
                ++k;
            if (k == needle.size())
                return i - k + 1;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.strStr("", "") << endl;
    return 0;
}
