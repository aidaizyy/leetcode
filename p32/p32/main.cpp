//
//  main.cpp
//  p32
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        /*
        //9ms
        int res = 0;
        stack<int> st;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }
        if (st.empty())
            res = (int)s.size();
        int top;
        int back = (int)s.size();
        while (!st.empty()) {
            top = st.top();
            st.pop();
            if (res < back - top - 1)
                res = back - top - 1;
            back = top;
        }
        if (res < back)
            res = back;
        return res;
        */
        
        //9ms
        int res = 0;
        int size = (int)s.size();
        vector<int> len(size+1, 0);
        len[0] = 0;
        len[1] = 0;
        for (int i=1; i<size; ++i) {
            if (s[i] == '(')
                len[i+1] = 0;
            else {
                if (s[i-1] == '(')
                    len[i+1] = len[i-1] + 2;
                else if (i-len[i]-1 >=0 && s[i-len[i]-1] == '(')
                    len[i+1] = len[i] + 2 + len[i-len[i]-1];
            }
            if (res < len[i+1])
                res = len[i+1];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.longestValidParentheses("(") << endl;
    return 0;
}
