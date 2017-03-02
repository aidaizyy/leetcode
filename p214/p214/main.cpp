//
//  main.cpp
//  p214
//
//  Created by 张云尧 on 2017/3/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        
        /*
        //216ms
        int size = (int)s.size();
        if (size <= 1)
            return s;
        int start = 0;
        int next;
        for (int i=size-1; i>=0; --i) {
            next = 0;
            if (s[i] == s[0]) {
                start = i;
                int j = i - 1;
                for (; j>i-j; --j) {
                    if (s[j] == s[0] && next != 0)
                        next = j;
                    if (s[j] != s[i-j])
                        break;
                }
                if (j <= i - j)
                    break;
            }
        }
        string res = s.substr(start+1, size-start-1);
        reverse(res.begin(), res.end());
        res += s;
        return res;
        */
        
        //3ms
        if (s.size() <= 1)
            return s;
        string res = s;
        reverse(res.begin(), res.end());
        res = s + "#" + res;
        int size = (int)res.size();
        int next[size+1];
        next[0] = 0;
        next[1] = 0;
        int k = 0;
        for (int i=1; i<size; ++i) {
            while (k > 0 && res[i] != res[k])
                k = next[k];
            if (res[i] == res[k])
                ++k;
            next[i+1] = k;
        }
        int i = next[size];
        res = s.substr(next[size], s.size()-next[size]);
        reverse(res.begin(), res.end());
        res += s;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.shortestPalindrome("aacecaaa") << endl;
    return 0;
}
