//
//  main.cpp
//  p115
//
//  Created by 张云尧 on 2017/4/13.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
        for (int j = 0; j < t.size(); ++j)
            dp[0][j] = 0;
        for (int i = 0; i < s.size(); ++i)
            dp[i][0] = 1;
        for (int j = 1; j <= t.size(); ++j) {
            for (int i = j; i <= s.size(); ++i) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] =  dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.numDistinct("ccc", "c");
    return 0;
}
