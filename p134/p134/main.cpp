//
//  main.cpp
//  p134
//
//  Created by 张云尧 on 2017/4/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        /*
        int n = (int)gas.size();
        vector<int> leave(n + 1, 0);
        int sum = 0;
        int pos = 0;
        int maximum = 0;
        for (int i = 0; i < n; ++i) {
            leave[i + 1] = leave[i] + gas[i] - cost[i];
            if (leave[i + 1] < 0)
                leave[i + 1] = 0;
            if (leave[i + 1] > maximum) {
                maximum = leave[i + 1];
                pos = i;
            }
            sum += gas[i] - cost[i];
        }
        if (sum < 0)
            return -1;
        if (leave[n] > 0 && leave[1] > 0) {
            int i;
            for (i = 1; i <= n; ++i) {
                if (leave[i] == 0) {
                    if (leave[n] + leave[i - 1] > maximum)
                        pos = i - 2;
                    break;
                }
            }
            if (i == n + 1)
                return 0;
        }
        for (int i = pos - 1; i != pos; --i) {
            if (i == -1)
                i = n - 1;
            if (leave[i + 1] == 0)
                return (i + 1) % n;
        }
        return 0;
        */

    
        int leave = 0;
        int sum = 0;
        int pos = 0;
        for (int i = 0; i < gas.size(); ++i) {
            leave += gas[i] - cost[i];
            if (leave < 0) {
                pos = i + 1;
                sum += leave;
                leave = 0;
            }
        }
        sum += leave;
        if (sum < 0)
            return -1;
        else
            return pos;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> gas = {1, 2};
    vector<int> cost = {2, 1};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
