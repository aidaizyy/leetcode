//
//  main.cpp
//  p122
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
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
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices = {1, 3, 2, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
