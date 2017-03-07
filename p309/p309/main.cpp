//
//  main.cpp
//  p309
//
//  Created by 张云尧 on 2017/3/7.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
        int buy[size], sell[size], cool[size];
        buy[0] = -prices[0];
        sell[0] = 0;
        cool[0] = 0;
        for (int i=1; i<size; ++i) {
            buy[i] = max(buy[i-1], cool[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            cool[i] = max(cool[i-1], sell[i-1]);
        }
        return max(sell[size-1], cool[size-1]);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices = {6,1,3,2,4,7};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
