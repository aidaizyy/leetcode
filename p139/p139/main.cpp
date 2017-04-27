//
//  main.cpp
//  p139
//
//  Created by 张云尧 on 2017/4/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (string str : wordDict) {
            set.insert(str);
        }
        
        /*
        //16ms O(n^3)
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int len = 1; len <= s.size(); ++len) {
            for (int i = 0; i < s.size() - len + 1; ++i) {
                if (set.find(s.substr(i, len)) != set.end())
                    dp[i][i + len - 1] = true;
                else {
                    for (int k = i; k < i + len -1; ++k) {
                        if (dp[i][k] && dp[k + 1][i + len - 1]) {
                            dp[i][i + len - 1] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
        */
        
        //6ms O(n^2)
        vector<bool> dp(vector<bool>(s.size() + 1, false));
        dp[0] = true;
        for (int j = 1; j <= s.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (dp[i] && set.find(s.substr(i, j - i)) != set.end()) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> wordDict = {"a", "abc", "b", "cd"};
    s.wordBreak("abcd", wordDict);
    return 0;
}
