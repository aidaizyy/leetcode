//
//  main.cpp
//  p187
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        /*
        //59ms
        vector<string> res;
        if (s.size() <= 10)
            return res;
        unordered_map<string, int> map;
        for (int i = 0; i <= s.size() - 10; ++i) {
            string str = s.substr(i, 10);
            if (map[str]++ == 1)
                res.push_back(str);
        }
        return res;
        */
        
        //33ms
        vector<string> res;
        if (s.size() <= 10)
            return res;
        unordered_map<int, int> map;
        int mark = 0;
        int i;
        for (i = 0; i < 9; ++i) {
            mark <<= 3;
            mark |= s[i] & 7;
        }
        for (i; i < s.size(); ++i) {
            mark <<= 3;
            mark &= 0x3FFFFFFF;
            mark |= s[i] & 7;
            if (map[mark]++ == 1)
                res.push_back(s.substr(i - 9, 10));
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.findRepeatedDnaSequences("AAAAAAAAAAA");
    return 0;
}
