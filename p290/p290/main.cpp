//
//  main.cpp
//  p290
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        /*
        vector<string> words;
        str += " ";
        string s = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                words.push_back(s);
                s = "";
            } else
                s += str[i];
        }
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, string> mymap;
        unordered_set<string> myset;
        for (int i = 0; i < pattern.size(); ++i) {
            if (mymap.find(pattern[i]) == mymap.end()) {
                if (myset.find(words[i]) != myset.end())
                    return false;
                else {
                    mymap[pattern[i]] = words[i];
                    myset.insert(words[i]);
                }
            } else if (mymap[pattern[i]] != words[i])
                return false;
        }
        return true;
        */
        
        vector<string> words;
        str += " ";
        string s = "";
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == ' ') {
                words.push_back(s);
                s = "";
            } else
                s += str[i];
        }
        if (pattern.size() != words.size())
            return false;
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        for (int i = 0; i < pattern.size(); ++i) {
            if (p2i[pattern[i]] != w2i[words[i]])
                return false;
            p2i[pattern[i]] = i + 1;
            w2i[words[i]] = i + 1;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.wordPattern("abba", "dog cat cat dog");
    return 0;
}
