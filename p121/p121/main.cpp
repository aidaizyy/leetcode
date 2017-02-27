//
//  main.cpp
//  p121
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
        /*
        int res = 0;
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
        int sum[size], min[size];
        sum[0] = 0;
        min[0] = prices[0];
        for (int i=1; i<size; ++i) {
            if (prices[i] < min[i-1]) {
                sum[i] = 0;
                min[i] = prices[i];
            } else {
                sum[i] = sum[i-1] + (prices[i] - prices[i-1]);
                min[i] = min[i-1];
            }
            if (res < sum[i])
                res = sum[i];
        }
        return res;
        */
        int res = 0;
        int size = (int)prices.size();
        if (size <= 1)
            return 0;
        int sum = 0;
        int min = prices[0];
        for (int i=1; i<size; ++i) {
            if (prices[i] < min) {
                sum = 0;
                min = prices[i];
            } else {
                sum += prices[i] - prices[i-1];
            }
            if (res < sum)
                res = sum;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {3, 4};
    cout << s.maxProfit(prices1) << endl;
    cout << s.maxProfit(prices2) << endl;
    cout << s.maxProfit(prices3) << endl;
    return 0;
}
