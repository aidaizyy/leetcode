//
//  main.cpp
//  p63
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = (int)obstacleGrid[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    if (i > 0)
                        dp[i][j] += dp[i-1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> obstacleGrid = {{0, 1}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
