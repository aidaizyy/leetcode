//
//  main.cpp
//  p97
//
//  Created by 张云尧 on 2017/4/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, true));
        for (int j = 1; j <= s2.size(); ++j)
            if (!(dp[0][j - 1] && s3[j - 1] == s2[j - 1]))
                dp[0][j] = false;
        for (int i = 1; i <= s1.size(); ++i)
            if (!(dp[i - 1][0] && s3[i - 1] == s1[i - 1]))
                dp[i][0] = false;
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (!((dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) || (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1])))
                    dp[i][j] = false;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.isInterleave("a", "b", "ab") << endl;
    return 0;
}
