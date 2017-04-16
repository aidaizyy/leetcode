//
//  main.cpp
//  p127
//
//  Created by 张云尧 on 2017/4/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        vector<bool> exist(wordList.size(), false);
        int res = INT_MAX;
        ladderLength(beginWord, endWord, wordList, exist, 2, res);
        return res == INT_MAX ? 0 : res;
    }
    void ladderLength(string beginWord, string endWord, vector<string>& wordList, vector<bool>& exist, int length, int& res) {
        if (length > res)
            return ;
        for (int i = 0; i < wordList.size(); ++i) {
            if (exist[i])
                continue;
            int counts = 0;
            for (int j = 0; j < beginWord.size(); ++j) {
                if (beginWord[j] != wordList[i][j])
                    ++counts;
                if (counts > 1)
                    break;
            }
            if (counts == 1) {
                if (wordList[i] == endWord) {
                    res = min(res, length);
                    continue ;
                }
                exist[i] = true;
                ladderLength(wordList[i], endWord, wordList, exist, length + 1, res);
                exist[i] = false;
            }
        }
    }
};
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for (string str : wordList)
            set.insert(str);
        if (set.find(endWord) == set.end())
            return 0;
        int res = 1;
        queue<string> queue;
        queue.push(beginWord);
        while (!queue.empty()) {
            int num = (int)queue.size();
            for (int k = 0; k < num; ++k) {
                string str = queue.front();
                if (str == endWord)
                    return res;
                queue.pop();
                for (int i = 0; i < beginWord.size(); ++i) {
                    char ch = str[i];
                    for (int j = 0; j < 26; ++j) {
                        str[i] = 'a' + j;
                        if (set.find(str) != set.end()) {
                            queue.push(str);
                            set.erase(str);
                        }
                    }
                    str[i] = ch;
                }
            }
            ++res;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;
    return 0;
}
