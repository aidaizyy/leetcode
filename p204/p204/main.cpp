//
//  main.cpp
//  p204
//
//  Created by 张云尧 on 2017/3/10.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> info(n, false);
        for (int i=2; i<n; ++i) {
            if (!info[i]) {
                ++res;
                if (i > n / i)
                    continue;
                for (int j=i*i; j<n; j+=i) {
                    info[j] = true;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.countPrimes(10) << endl;
    return 0;
}
