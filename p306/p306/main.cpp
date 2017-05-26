//
//  main.cpp
//  p306
//
//  Created by 张云尧 on 2017/5/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = (int)num.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int t = max(i + 1, j - i);
                if (j + t >= n)
                    break;
                if ((num[i] - '0' + num[j] - '0') % 10 != (num[j + t] - '0') && (j + t + 1 == n || (num[i] - '0' + num[j] - '0') % 10 != (num[j + t + 1] - '0')))
                    continue;
                if (j - i > 1 && num[i + 1] == '0')
                    continue;
                int num1 = stoi(num.substr(0, i + 1));
                int num2 = stoi(num.substr(i + 1, j - i));
                if (helper(num, (long long)num1, (long long)num2, j + 1))
                    return true;
            }
        }
        return false;
    }
    
    bool helper(string num, long long num1, long long num2, int start) {
        if (start == num.size())
            return true;
        long long num3 = num1 + num2;
        if (num3 != 0 && num[start] == '0')
            return false;
        string str = to_string(num3);
        if (start + str.size() - 1 >= num.size())
            return false;
        int n = (int)str.size();
        if (num.substr(start, n) != str)
            return false;
        if (helper(num, num2, num3, start + n))
            return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.isAdditiveNumber("121474836472147483648");
    return 0;
}
