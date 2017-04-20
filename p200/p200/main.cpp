//
//  main.cpp
//  p200
//
//  Created by 张云尧 on 2017/4/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = (int)grid.size();
        if (m == 0)
            return 0;
        int n = (int)grid[0].size();
        int res = 0;
        queue<int> queue;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    queue.push(i * n + j);
                    while (!queue.empty()) {
                        int tmp = queue.front();
                        queue.pop();
                        int k = tmp / n;
                        int l = tmp % n;
                        if (grid[k][l] != '1')
                            continue;
                        grid[k][l] = '2';
                        if (l != 0)
                            queue.push(tmp - 1);
                        if (l != n - 1)
                            queue.push(tmp + 1);
                        if (k != 0)
                            queue.push(tmp - n);
                        if (k != m - 1)
                            queue.push(tmp + n);
                    }
                    ++res;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
