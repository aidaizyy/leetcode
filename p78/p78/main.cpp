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
    
    /*
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> item;
        helper1(res, nums, item, 0);
        helper2(res, nums, item, 0);
        return res;
    }
    void helper1(vector<vector<int>>& res, vector<int>& nums, vector<int> item, int pos) {
        if (pos == nums.size()) {
            res.push_back(item);
            return ;
        }
        helper(res, nums, item, pos + 1);
        item.push_back(nums[pos]);
        helper(res, nums, item, pos + 1);
    }
    void helper2(vector<vector<int>>& res, vector<int>& nums, vector<int>& item, int pos) {
        res.push_back(item);
        for (int i = pos; i < nums.size(); ++i) {
            item.push_back(nums[i]);
            helper(res, nums, item, i + 1);
            item.pop_back();
        }
    }
    */
    
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
