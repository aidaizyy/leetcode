//
//  main.cpp
//  p438
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> hash(256, 0);
        for (char c : p) {
            ++hash[c];
        }
        int left = 0;
        int right = 0;
        int count = (int)p.size();
        while (right < s.size()) {
            if (hash[s[right++]]-- >= 1)
                --count;
            if (count == 0)
                res.push_back(left);
            if (right - left == p.size() && hash[s[left++]]++ >= 0)
                ++count;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.findAnagrams("cbaebacbacd", "abc");
    return 0;
}
