//
//  main.cpp
//  p72
//
//  Created by 张云尧 on 2017/3/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = (int)word1.size();
        int n = (int)word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for (int i = 0; i <= n; ++i)
            dp[0][i] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
