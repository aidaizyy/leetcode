//
//  main.cpp
//  p22
//
//  Created by 张云尧 on 2017/3/8.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    
    /*
    //6ms
    bool isVaild(string str, int n) {
        int m = 0;
        for (int i=0; i<str.size(); ++i) {
            if (str[i] == '(')
                ++m;
        }
        if (m > n)
            return false;
        stack<char> stack;
        for (int i=0; i<str.size(); ++i) {
            if (str[i] == '(')
                stack.push('(');
            else {
                if (stack.empty())
                    return false;
                else if (stack.top() == '(')
                    stack.pop();
                else
                    return false;
            }
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<string> queue;
        if (n < 1)
            return res;
        queue.push("(");
        for (int i=0; i<2*n-1; ++i) {
            int m = (int)queue.size();
            for (int j=0; j<m; ++j) {
                string str = queue.front();
                if (isVaild(str+'(', n))
                    queue.push(str+'(');
                if (isVaild(str+')', n))
                    queue.push(str+')');
                queue.pop();
            }
        }
        int m = (int)queue.size();
        for (int i=0; i<m; ++i) {
            res.push_back(queue.front());
            queue.pop();
        }
        return res;
    }
    */
    
    //3ms
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, 0);
        return res;
    }
    void helper(vector<string>& res, string str, int n, int m) {
        if (n == 0 && m == 0) {
            res.push_back(str);
            return ;
        }
        if (n > 0)
            helper(res, str+'(', n-1, m+1);
        if (m > 0)
            helper(res, str+')', n, m-1);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.generateParenthesis(3);
    return 0;
}
