//
//  main.cpp
//  p140
//
//  Created by 张云尧 on 2017/4/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (string str : wordDict) {
            set.insert(str);
        }
        unordered_map<string, vector<string>> map;
        return wordBreak(s, set, map);
    }
    vector<string> wordBreak(string s, unordered_set<string>& set, unordered_map<string, vector<string>>& map) {
        if (map.find(s) != map.end())
            return map[s];
        vector<string> res;
        if (set.find(s) != set.end()) {
            res.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i) {
            string back = s.substr(i);
            if (set.find(back) != set.end()) {
                string front = s.substr(0, i);
                vector<string> prev;
                prev = wordBreak(front, set, map);
                for (int i = 0; i < prev.size(); ++i){
                    prev[i] += " " + back;
                }
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        map[s] = res;
        return res;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    s.wordBreak("catsanddog", wordDict);
    return 0;
}
