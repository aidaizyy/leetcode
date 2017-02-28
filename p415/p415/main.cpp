//
//  main.cpp
//  p415
//
//  Created by 张云尧 on 2017/2/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = (int)num1.size();
        int n = (int)num2.size();
        while (m && n) {
            res += char(num1[--m] + num2[--n] - '0');
        }
        while (m) {
            res += num1[--m];
        }
        while (n) {
            res += num2[--n];
        }
        int size = (int)res.size();
        for (int i=0; i<size-1; ++i) {
            if (res[i] > '9') {
                res[i] -= 10;
                res[i+1] += 1;
            }
        }
        if (res[size-1] > '9') {
            res[size-1] -= 10;
            res += "1";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
