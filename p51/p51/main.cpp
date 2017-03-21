//
//  main.cpp
//  p51
//
//  Created by 张云尧 on 2017/3/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> map(n, string(n, '.'));
        helper(res, map, n, 0);
        return res;
    }
    void helper(vector<vector<string>>& res, vector<string>& map, int n, int i) {
        if (i == n) {
            res.push_back(map);
            return ;
        }
        for (int j = 0; j < n; ++j) {
            if (isConflict(map, n, i, j))
                continue;
            map[i][j] = 'Q';
            helper(res, map, n, i + 1);
            map[i][j] = '.';
        }
    }
    bool isConflict(vector<string>& map, int n, int i, int j) {
        for (int k = 0; k < n; ++k) {
            if (map[i][k] == 'Q')
                return false;
            if (map[k][j] == 'Q')
                return false;
            if (j - i + k >= 0 && j - i + k < n && map[k][j-i+k] == 'Q')
                return false;
            if (i + j - k >= 0 && i + j - k < n && map[k][i+j-k] == 'Q')
                return true;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.solveNQueens(4);
    return 0;
}
