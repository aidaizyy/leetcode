//
//  main.cpp
//  p59
//
//  Created by 张云尧 on 2017/3/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int value = 1;
        for (int i = 0; i < n + 1 / 2; ++i) {
            if (i == n - i - 1) {
                for (int j = 0; j < n-2*i; ++j)
                    res[i][i+j] = value++;
            } else {
                for (int j = 0; j < n-2*i-1; ++j)
                    res[i][i+j] = value++;
                for (int j = 0; j < n-2*i-1; ++j)
                    res[i+j][n-i-1] = value++;
                for (int j = 0; j < n-2*i-1; ++j)
                    res[n-i-1][n-i-j-1] = value++;
                for (int j = 0; j < n-2*i-1; ++j)
                    res[n-i-j-1][i] = value++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
