//
//  main.cpp
//  p54
//
//  Created by 张云尧 on 2017/3/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        for (int i = 0; i < (min(m, n) + 1) / 2; ++i) {
            if (i == m - i - 1) {
                for (int j = 0; j < n-2*i; ++j)
                    res.push_back(matrix[i][i+j]);
            } else if (i == n - i - 1) {
                for (int j = 0; j < m-2*i; ++j)
                    res.push_back(matrix[i+j][n-i-1]);
            } else {
                for (int j = 0; j < n-2*i-1; ++j)
                    res.push_back(matrix[i][i+j]);
                for (int j = 0; j < m-2*i-1; ++j)
                    res.push_back(matrix[i+j][n-i-1]);
                for (int j = 0; j < n-2*i-1; ++j)
                    res.push_back(matrix[m-i-1][n-i-j-1]);
                for (int j = 0; j < m-2*i-1; ++j)
                    res.push_back(matrix[m-i-j-1][i]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.spiralOrder(matrix);
    return 0;
}
