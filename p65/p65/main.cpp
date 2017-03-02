//
//  main.cpp
//  p65
//
//  Created by 张云尧 on 2017/3/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int size = (int)s.size();
        while (s[i] == ' ')
            ++i;
        if (s[i] == '-')
            ++i;
        else if (s[i] == '+')
            ++i;
        int flag = 0;
        while (i < size && s[i] >= '0' && s[i] <= '9') {
            if (flag == 0)
                flag = 1;
            ++i;
        }
        if (i < size && s[i] == '.') {
            ++i;
        }
        while (i < size && s[i] >= '0' && s[i] <= '9') {
            if (flag == 0)
                flag = 1;
            ++i;
        }
        if (i < size && s[i] == 'e') {
            if (flag == 1)
                flag = 2;
            ++i;
            if (i < size && (s[i] == '+' || s[i] == '-'))
                ++i;
        }
        while (i < size && s[i] >= '0' && s[i] <= '9') {
            if (flag == 2)
                flag = 1;
            ++i;
        }
        while (s[i] == ' ')
            ++i;
        if (i == size && flag == 1)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isNumber("2.3e3") << endl;
    return 0;
}
