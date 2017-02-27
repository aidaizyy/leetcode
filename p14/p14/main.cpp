//
//  main.cpp
//  p14
//
//  Created by 张云尧 on 2017/2/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int num = (int)strs.size();
        if (num == 0)
            return res;
        int size = (int)strs[0].size();
        for (string s : strs) {
            if (size < s.size())
                size = (int)s.size();
        }
        for (int i=0; i<size; ++i) {
            char c = strs[0][i];
            for (string s : strs) {
                if (c != s[i])
                    return res;
            }
            res += c;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
