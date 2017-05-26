//
//  main.cpp
//  p303
//
//  Created by 张云尧 on 2017/5/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        int n = (int)nums.size();
        sum.resize(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
    
    vector<int> sum;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
