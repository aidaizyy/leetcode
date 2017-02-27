//
//  main.cpp
//  p125
//
//  Created by 张云尧 on 2017/2/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int size = (int)s.size();
        int i = 0;
        int j = size - 1;
        while (i <= j) {
            while (!isAlphanumeric(s[i]) && i < size-1)
                ++i;
            while (!isAlphanumeric(s[j]) && j > 0)
                --j;
            if (i <= j && s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    bool isAlphanumeric(char& c) {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return true;
        else if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
