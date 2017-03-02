//
//  main.cpp
//  p5
//
//  Created by 张云尧 on 2017/3/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int beg = 0;
        int len = 1;
        int size = (int)s.size();
        for (int i=0; i<size-1; ++i) {
            int j = 0;
            while(i-j>=0 && i+j+2<size && s[i-j] == s[i+j+2])
                ++j;
            if (len < 2 * j + 1) {
                beg = i - j + 1;
                len = 2 * j + 1;
            }
            j = 0;
            while(i-j>=0 && i+j+2<size && s[i-j] == s[i+j+1])
                ++j;
            if (len < 2 * j) {
                beg = i - j + 1;
                len = 2 * j;
            }
        }
        return s.substr(beg, len);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    cout << s.longestPalindrome("cbbd") << endl;
    cout << s.longestPalindrome("bb") << endl;
    return 0;
}
