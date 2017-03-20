//
//  main.cpp
//  p49
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_multimap<string, string> hashmap;
        for (string str : strs) {
            string tmp = str;
            sort(str.begin(), str.end());
            hashmap.insert(pair<string, string>(str, tmp));
        }
        string type = "*";
        int pos = -1;
        for (pair<string, string> p : hashmap) {
            if (p.first != type) {
                res.push_back(vector<string>({p.second}));
                type = p.first;
                ++pos;
            } else
                res[pos].push_back(p.second);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> strs = {""};
    s.groupAnagrams(strs);
    return 0;
}
