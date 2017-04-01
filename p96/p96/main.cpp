//
//  main.cpp
//  p96
//
//  Created by 张云尧 on 2017/3/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                dp[j][j + i] += dp[j + 1][j + i];
                dp[j][j + i] += dp[j][j + i - 1];
                for (int k = j + 1; k < n - 1; ++k) {
                    dp[j][i + j] += dp[j][k - 1] * dp[k + 1][i + j];
                }
            }
        }
        return dp[0][n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
