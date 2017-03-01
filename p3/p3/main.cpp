//
//  main.cpp
//  p3
//
//  Created by 张云尧 on 2017/3/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /*
        //29ms
        int res = 0;
        set<char> set;
        for (int first=0,last=0; last<s.size(); ++last) {
            if (set.count(s[last]) == 0) {
                set.insert(s[last]);
                if (res < last - first + 1)
                    res = last - first + 1;
            } else {
                while (first <= last) {
                    if (s[first++] == s[last])
                        break;
                    else
                        set.erase(s[first-1]);
                }
            }
        }
        return res;
        */
        
        //29ms
        int res = 0;
        map<char, int> map;
        for (int first=0,last=0; last<s.size(); ++last) {
            if (map.find(s[last]) != map.end() && map[s[last]] >= first) {
                first = map[s[last]] + 1;
            }
            if (res < last - first + 1)
                res = last - first + 1;
            map[s[last]] = last;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
