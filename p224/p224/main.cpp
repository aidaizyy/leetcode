//
//  main.cpp
//  p224
//
//  Created by 张云尧 on 2017/4/11.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        s = "(" + s + ")";
        stack<int> num;
        stack<char> opr;
        int tmp = 0;
        bool isNum = false;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                tmp *= 10;
                tmp += c - '0';
                isNum = true;
            } else {
                if (isNum) {
                    num.push(tmp);
                    tmp = 0;
                    isNum = false;
                }
                if (c == '(') {
                    opr.push(c);
                } else if (c == '+' || c == '-') {
                    if (opr.top() != '(')
                        calculate(num, opr);
                    opr.push(c);
                } else if (c == ')') {
                    if (opr.top() != '(')
                        calculate(num, opr);
                    opr.pop();
                }
            }
        }
        return num.top();
    }
    void calculate(stack<int>& num, stack<char>& opr) {
        int y = num.top();
        num.pop();
        int x = num.top();
        num.pop();
        char c = opr.top();
        int z;
        if (c == '+')
            z = x + y;
        else if (c == '-')
            z = x - y;
        else if (c == '*')
            z = x * y;
        else
            z = x / y;
        num.push(z);
        opr.pop();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.calculate("1 + 1");
    return 0;
}
