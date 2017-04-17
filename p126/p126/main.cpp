//
//  main.cpp
//  p126
//
//  Created by 张云尧 on 2017/4/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> set;
        for (string str : wordList)
            set.insert(str);
        if (set.find(endWord) == set.end())
            return res;
        int minStep = INT_MAX;
        int step = 1;
        queue<string> queue;
        queue.push(beginWord);
        vector<vector<string>> path;
        path.push_back(vector<string>{beginWord});
        while (!queue.empty() && step <= minStep) {
            path.push_back({});
            int num = (int)queue.size();
            for (int k = 0; k < num; ++k) {
                string str = queue.front();
                queue.pop();
                for (int i = 0; i < beginWord.size(); ++i) {
                    char ch = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (set.find(str) != set.end()) {
                            if (str == endWord)
                                minStep = step;
                            queue.push(str);
                            set.erase(str);
                            path[step].push_back(str);
                        }
                    }
                    str[i] = ch;
                }
            }
            ++step;
        }
        vector<string> tmp;
        res.push_back(vector<string>{endWord});
        for (int i = (int)path.size() - 2; i >= 0; --i) {
            int resNum = (int)res.size();
            for (int j = 0; j < resNum; ++j) {
                for (int k = 0; k < path[i].size(); ++k) {
                    if (canTransform(res[j].back(), path[i][k])) {
                        tmp = res[j];
                        tmp.push_back(path[i][k]);
                        res.push_back(tmp);
                    }
                }
            }
            res.erase(res.begin(), res.begin() + resNum);
        }
        for (vector<string>& vs : res)
            reverse(vs.begin(), vs.end());
        return res;
    }
    bool canTransform(string& s, string& t) {
        int counts = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i])
                ++counts;
            if (counts > 1)
                break;
        }
        return counts == 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "cog", wordList);
    return 0;
}
