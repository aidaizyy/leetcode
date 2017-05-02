//
//  main.cpp
//  p264
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return 1;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> v(n);
        v[0] = 1;
        for (int i = 1; i < n; ++i) {
            v[i] = min(min(v[t2] * 2, v[t3] * 3), v[t5] * 5);
            if (v[i] == v[t2] * 2)
                ++t2;
            if (v[i] == v[t3] * 3)
                ++t3;
            if (v[i] == v[t5] * 5)
                ++t5;
        }
        return v[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.nthUglyNumber(11);
    return 0;
}
