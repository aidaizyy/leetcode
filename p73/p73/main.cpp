//
//  main.cpp
//  p73
//
//  Created by 张云尧 on 2017/3/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        /*
        //queue
        if (matrix.empty())
            return ;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        queue<int> que;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0)
                    que.push(i * n + j);
            }
        }
        while (!que.empty()) {
            int h = que.front() / n;
            int v = que.front() % n;
            for (int i = 0; i < m; ++i)
                matrix[i][v] = 0;
            for (int j = 0; j < n; ++j)
                matrix[h][j] = 0;
            que.pop();
        }
        */
        
        //in-place
        if (matrix.empty())
            return ;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
