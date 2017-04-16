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
