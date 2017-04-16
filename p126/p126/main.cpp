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
        vector<vector<string>> path;
        unordered_set<string> set;
        for (string str : wordList)
            set.insert(str);
        if (set.find(endWord) == set.end())
            return path;
        int minStep = INT_MAX;
        int step = 1;
        queue<string> queue;
        queue.push(beginWord);
        vector<string> tmp;
        tmp.push_back(beginWord);
        path.push_back(tmp);
        while (!queue.empty() && step <= minStep) {
            int num = (int)queue.size();
            int pathNum = path.size();
            for (int k = 0; k < num; ++k) {
                string str = queue.front();
                if (str == endWord)
                    minStep = step;
                queue.pop();
                string last = str;
                for (int i = 0; i < beginWord.size(); ++i) {
                    char ch = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (set.find(str) != set.end() && str != last) {
                            queue.push(str);
                            for (int p = 0; p < pathNum; ++p) {
                                if (path[p].back() == last) {
                                    tmp = path[p];
                                    tmp.push_back(str);
                                    if (find(path.begin(), path.end(), tmp) == path.end())
                                        path.push_back(tmp);
                                }
                            }
                        }
                    }
                    str[i] = ch;
                }
            }
            ++step;
        }
        vector<vector<string>> res;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i].back() == endWord && path[i].size() == minStep)
                res.push_back(path[i]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "cog", wordList);
    return 0;
}
