//
//  main.cpp
//  p20
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (st.size() != 0) {
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))
                    st.pop();
                else
                    return false;
            } else
                return false;
        }
        if (st.size() == 0)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isValid("((([[{}]])))") << endl;
    cout << s.isValid("([][]({}))({[][]})") << endl;
    return 0;
}
