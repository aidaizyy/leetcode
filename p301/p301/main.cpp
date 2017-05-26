//
//  main.cpp
//  p301
//
//  Created by 张云尧 on 2017/5/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        remove(res, s, 0, 0, vector<char>({'(', ')'}));
        return res;
    }
    
    void remove(vector<string>& res, string s, int lastI, int lastJ, vector<char> par) {
        for (int stack = 0, i = lastI; i < s.size(); ++i) {
            if (s[i] == par[0])
                ++stack;
            if (s[i] == par[1])
                --stack;
            if (stack >= 0)
                continue;
            for (int j = lastJ; j <= i; ++j) {
                if (s[j] == par[1] && (j == lastJ || s[j - 1] != par[1]))
                    remove(res, s.substr(0, j) + s.substr(j + 1, s.size() - j - 1), i, j, par);
            }
            return ;
        }
        string t = s;
        reverse(t.begin(), t.end());
        if (par[0] == '(')
            remove(res, t, 0, 0, vector<char>({')', '('}));
        else
            res.push_back(t);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.removeInvalidParentheses("()())()");
    return 0;
}
