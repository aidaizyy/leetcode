//
//  main.cpp
//  p188
//
//  Created by 张云尧 on 2017/3/7.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
        if (size / 2 < k) {
            int res = 0;
            int prev = prices[0];
            for (int i=1; i<size; ++i) {
                if (prices[i] < prices[i-1]) {
                    res += prices[i-1] - prev;
                    prev = prices[i];
                }
            }
            res += prices[size-1] - prev;
            return res;
        }
         vector<vector<int>> profit(k+1, vector<int>(size+1, 0));
        for (int i=1; i<=k; ++i) {
            int tmp = profit[i-1][0] - prices[0];
            for (int j=1; j<=size; ++j) {
                profit[i][j] = max(profit[i][j-1], tmp + prices[j-1]);
                if ( j < size ) {
                    tmp = max(tmp, profit[i-1][j] - prices[j]);
                }
            }
        }
        return profit[k][size];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices{1, 4, 2};
    cout << s.maxProfit(2, prices) << endl;
    return 0;
}
