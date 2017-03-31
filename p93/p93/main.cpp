//
//  main.cpp
//  p93
//
//  Created by 张云尧 on 2017/3/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = (int)s.size();
        if (n < 4 || n > 12)
            return res;
        for (int i = 1; i <= min(n - 3, 3); ++i) {
            if (!isValid(s.substr(0, i)))
                continue;
            for (int j = i + 1; j <= min(n - 2, i + 3); ++j) {
                if (!isValid(s.substr(i, j - i)))
                    continue;
                for (int k = j + 1; k <= min(n - 1, j + 3); ++k) {
                    if (!isValid(s.substr(j, k - j)))
                        continue;
                    if (!isValid(s.substr(k, n - k)))
                        continue;
                    string t = s;
                    t.insert(i, ".");
                    t.insert(j + 1, ".");
                    t.insert(k + 2, ".");
                    res.push_back(t);
                }
            }
        }
        return res;
    }
    bool isValid(string s) {
        int n = (int)s.size();
        if (n == 0 || n > 3)
            return false;
        if (n != 1 && s[0] == '0')
            return false;
        int ip = 0;
        int i = 0;
        while (i != s.size()) {
            ip *= 10;
            ip += s[i++] - '0';
        }
        if (ip > 255)
            return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
