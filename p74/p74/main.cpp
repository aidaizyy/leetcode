//
//  main.cpp
//  p74
//
//  Created by 张云尧 on 2017/3/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (i == m - 1 || target < matrix[i + 1][0] ) {
                int left = 0;
                int right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (target == matrix[i][mid])
                        return true;
                    else if (target > matrix[i][mid])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                return false;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
