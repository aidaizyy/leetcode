//
//  main.cpp
//  p120
//
//  Created by 张云尧 on 2017/4/14.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = (int)triangle.size();
        if (size == 0)
            return 0;
        vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> trangle = {{-1},{2,3},{1,-1,-3}};
    s.minimumTotal(trangle);
    return 0;
}
