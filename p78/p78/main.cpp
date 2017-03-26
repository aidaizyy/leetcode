//
//  main.cpp
//  p78
//
//  Created by 张云尧 on 2017/3/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = (int)nums.size();
        int num = pow(2, size);
        vector<vector<int>> res(num, vector<int>());
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < num; ++j) {
                if ((j << i) & 1)
                    res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
