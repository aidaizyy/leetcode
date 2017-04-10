//
//  main.cpp
//  p150
//
//  Created by 张云尧 on 2017/4/11.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s[0] >= '0' && s[0] <= '9') {
                int tmp = 0;
                for (int i = 0; i < s.size(); ++i) {
                    tmp *= 10;
                    tmp += s[i] - '0';
                }
                st.push(tmp);
            } else if (s.size() > 1 && s[0] == '-') {
                int tmp = 0;
                for (int i = 1; i < s.size(); ++i) {
                    tmp *= 10;
                    tmp += s[i] - '0';
                }
                if (s[0] == '-')
                    tmp *= -1;
                st.push(tmp);
            } else {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                st.push(evaluate(x, y, s[0]));
            }
        }
        return st.top();
    }
    int evaluate(int x, int y, char c) {
        if (c == '+')
            return x + y;
        else if (c == '-')
            return x - y;
        else if (c == '*')
            return x * y;
        else
            return x / y;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
