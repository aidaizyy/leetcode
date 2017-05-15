//
//  main.cpp
//  p282
//
//  Created by 张云尧 on 2017/5/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.size() == 0)
            return res;
        addOperators(res, "", num, target, 0, 0, 0);
        return res;
    }
    void addOperators(vector<string>& res, string path, string& num, int target, int pos, long long prev, long long multed) {
        if (pos == num.size()) {
            if (prev == target)
                res.push_back(path);
            return ;
        }
        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0')
                break;
            string nextStr = num.substr(pos, i - pos + 1);
            long long next = stoll(nextStr);
            if (pos == 0) {
                addOperators(res, path + nextStr, num, target, i + 1, next, next);
            } else {
                addOperators(res, path + "+" + nextStr, num, target, i + 1, prev + next, next);
                addOperators(res, path + "-" + nextStr, num, target, i + 1, prev - next, -next);
                addOperators(res, path + "*" + nextStr, num, target, i + 1, prev - multed + multed * next, multed * next);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.addOperators("123", 6);
    return 0;
}
