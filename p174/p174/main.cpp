//
//  main.cpp
//  p174
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)
            return 0;
        int m = (int)dungeon.size();
        int n = (int)dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m-1][n-1] = dungeon[m-1][n-1];
        for (int i = m - 2; i >= 0; --i)
            dp[i][n-1] = min(dp[i+1][n-1] + dungeon[i][n-1], dungeon[i][n-1]);
        for (int i = n - 2; i >= 0; --i)
            dp[m-1][i] = min(dp[m-1][i+1] + dungeon[m-1][i], dungeon[m-1][i]);
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = min(max(dp[i+1][j], dp[i][j+1]) + dungeon[i][j], dungeon[i][j]);
            }
        }
        return max(1, 1 - dp[0][0]);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> dungeon = {{0, -3}, {-10, 0}};
    cout << s.calculateMinimumHP(dungeon) << endl;
    return 0;
}
