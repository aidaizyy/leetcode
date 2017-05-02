//
//  main.cpp
//  p279
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    
    /*
    //122ms
    int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    return dp[n];
    */
    
    //3ms
    int numSquares(int n) {
        if (isSquare(n)) {
            return 1;
        }
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        int m = (int)sqrt(n);
        for (int i = 1; i <= m; ++i) {
            if (isSquare(n - i * i))
                return 2;
        }
        return 3;
    }
    bool isSquare(int n) {
        int m = (int)sqrt(n);
        return m * m == n;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.numSquares(6);
    return 0;
}
