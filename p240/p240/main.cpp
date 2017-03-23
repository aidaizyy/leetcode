//
//  main.cpp
//  p240
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
        
        /*
        //106ms
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                int left = 0, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (target == matrix[i][mid])
                        return true;
                    else if (target > matrix[i][mid])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return false;
        */
        
        //65ms
        if (matrix.empty())
            return false;
        int i = (int)matrix.size() - 1;
        int j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                ++j;
            else
                --i;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    cout << s.searchMatrix(matrix, 15) << endl;
    return 0;
}
