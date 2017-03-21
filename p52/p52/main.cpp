//
//  main.cpp
//  p52
//
//  Created by 张云尧 on 2017/3/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, false);
        vector<bool> main(2*n-1, false);
        vector<bool> anti(2*n-1, false);
        helper(res, col, main, anti, n, 0);
        return res;
    }
    void helper(int& res, vector<bool>& col, vector<bool>& main, vector<bool>& anti, int n, int i) {
        if (i == n) {
            ++res;
            return ;
        }
        for (int j = 0; j < n; ++j) {
            if (col[j] || main[j+i] || anti[j-i+n])
                continue;
            col[j] = main[j+i] = anti[j-i+n] = true;
            helper(res, col, main, anti, n, i + 1);
            col[j] = main[j+i] = anti[j-i+n] = false;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
}
