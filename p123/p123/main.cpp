//
//  main.cpp
//  p123
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
        if (size < 2)
            return 0;
        int ml[size], mr[size];
        ml[0] = 0;
        mr[size-1] = 0;
        int minv = prices[0];
        int maxv = prices[size-1];
        for (int i=1; i<size; ++i) {
            if (prices[i] < minv)
                minv = prices[i];
            ml[i] = max(ml[i-1], prices[i] - minv);
        }
        for (int i=size-2; i>=0; --i) {
            if (prices[i] > maxv)
                maxv = prices[i];
            mr[i] = max(mr[i+1], maxv - prices[i]);
        }
        int res = 0;
        for (int i=0; i<size; ++i) {
            if (res < ml[i] + mr[i])
                res = ml[i] + mr[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> prices = {3,2,6,5,0,3};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
