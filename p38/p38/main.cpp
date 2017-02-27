//
//  main.cpp
//  p38
//
//  Created by 张云尧 on 2017/2/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string res = "";
        string str = countAndSay(n-1);
        char pre = str[0];
        int num = 1;
        for (int i=1; i<str.size(); ++i) {
            if (str[i] != pre) {
                res += '0' + num;
                res += pre;
                pre = str[i];
                num = 1;
            } else {
                ++num;
            }
        }
        res += '0' + num;
        res += pre;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countAndSay(4) << endl;
    return 0;
}
