//
//  main.cpp
//  p85
//
//  Created by 张云尧 on 2017/3/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            int cleft = 0;
            int cright = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cleft);
                else {
                    left[j] = 0;
                    cleft = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cright);
                else {
                    right[j] = n;
                    cright = j;
                }
            }
            for (int j = 0; j < n; ++j)
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
        return maxArea;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<char>> matrix = {{'0', '1'}, {'0', '1'}};
    //vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}
