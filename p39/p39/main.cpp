//
//  main.cpp
//  p39
//
//  Created by 张云尧 on 2017/3/8.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> group;
        helper(res, candidates, group, 0, target);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> candidates, vector<int> group, int pos, int target) {
        for (int i=pos; i<candidates.size(); ++i) {
            if (candidates[i] < target) {
                group.push_back(candidates[i]);
                helper(res, candidates, group, i, target-candidates[i]);
                group.pop_back();
            } else if (candidates[i] == target) {
                group.push_back(candidates[i]);
                res.push_back(group);
                group.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> candidates = {4, 2, 8};
    s.combinationSum(candidates, 8);
    return 0;
}
