//
//  main.cpp
//  p132
//
//  Created by 张云尧 on 2017/4/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        
        /*
        //9ms
        int n = (int)s.size();
        vector<int> dp(n);
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            int minimum = j;
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (i + 1 > j - 1 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                    if (i == 0) {
                        minimum = 0;
                    } else
                        minimum = min(minimum, dp[i - 1] + 1);
                }
            }
            dp[j] = minimum;
        }
        return dp[n - 1];
        */
        
        /*
        //9ms
        int n = (int)s.size();
        vector<int> dp(n);
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
                isPalindrome[i - j][i + j] = true;
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j)
                isPalindrome[i - j][i + j + 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            int minimum = j;
            for (int i = 0; i <= j; ++i) {
                if (isPalindrome[i][j]) {
                    if (i == 0) {
                        minimum = 0;
                        break;
                    } else
                        minimum = min(minimum, dp[i - 1] + 1);
                }
            }
            dp[j] = minimum;
        }
        return dp[n - 1];
        */
        
        //3ms
        int n = (int)s.size();
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; ++i)
            dp[i] = i - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j)
                dp[i + j + 2] = min(dp[i + j + 2], dp[i - j] + 1);
        }
        return dp[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.minCut("aab") << endl;
    return 0;
}
