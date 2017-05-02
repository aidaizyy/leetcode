//
//  main.cpp
//  p205
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        /*
        //9ms
        if (s.size() != t.size())
            return false;
        unordered_map<int, int> mymap;
        unordered_set<int> myset;
        for (int i = 0; i < s.size(); ++i) {
            if (mymap.find(s[i]) == mymap.end()) {
                if (myset.find(t[i]) != myset.end())
                    return false;
                else {
                    mymap[s[i]] = t[i];
                    myset.insert(t[i]);
                }
            } else if (mymap[s[i]] != t[i])
                return false;
        }
        return true;
        */
        
        //6ms
        if (s.size() != t.size())
            return false;
        vector<int> map1(256, 0), map2(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = i + 1;
            map2[t[i]] = i + 1;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
