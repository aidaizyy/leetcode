//
//  main.cpp
//  p76
//
//  Created by 张云尧 on 2017/3/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        //46ms
        int start = - 1;
        int len = (int)s.size();
        unordered_map<char, int> counts;
        for (char ch : t)
            ++counts[ch];
        unordered_map<char, int> seen;
        int num = 0;
        int left = 0;
        while (left != s.size()) {
            if (counts.find(s[left]) == counts.end()) {
                ++left;
                continue;
            }
            break;
        }
        int right = left;
        while (right != s.size()) {
            if (counts.find(s[right]) == counts.end()) {
                ++right;
                continue;
            }
            ++seen[s[right]];
            if (seen[s[right]] <= counts[s[right]])
                ++num;
            if (num == t.size()) {
                if (right - left + 1 <= len) {
                    start = left;
                    len = right - left + 1;
                }
                --seen[s[left]];
                ++left;
                --num;
            }
            while (left != s.size() && (counts.find(s[left]) == counts.end() || seen[s[left]] > counts[s[left]])) {
                if (counts.find(s[left]) != counts.end())
                    --seen[s[left]];
                ++left;
            }
            if (right < left)
                right = left;
            else
                ++right;
        }
        return start == -1 ? "" : s.substr(start, len);
        */
        
        //9ms
        vector<int> map(128,0);
        for(char ch: t)
            ++map[ch];
        int start = -1;
        int len = (int)s.size() + 1;
        int left = 0;
        int right = 0;
        int num = (int)t.size();
        while (right != s.size()) {
            if (map[s[right]]-- > 0)
                --num;
            while (num == 0) {
                if (right - left + 1 < len) {
                    start = left;
                    len = right - left + 1;
                }
                if (map[s[left]]++ == 0)
                    ++num;
                ++left;
            }
            ++right;
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minWindow("abc"
                        ,"ac") << endl;
    return 0;
}
