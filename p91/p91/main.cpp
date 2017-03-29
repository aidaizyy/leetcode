//
//  main.cpp
//  p91
//
//  Created by 张云尧 on 2017/3/29.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        if (s[n - 1] == '0')
            dp[n - 1] = 0;
        else
            dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            else if (s[i] <= '1' || (s[i] == '2' && s[i + 1] <= '6'))
                dp[i] = dp[i + 1] + dp[i + 2];
            else
                dp[i] = dp[i + 1];
            
        }
        return dp[0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numDecodings("27") << endl;
    return 0;
}
