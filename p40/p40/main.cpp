//
//  main.cpp
//  p40
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> group;
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, group, -1, target);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int> candidates, vector<int> group, int pos, int target) {
        for (int i=pos+1; i<candidates.size(); ++i) {
            if (i != pos+1 && candidates[i] == candidates[i-1])
                continue;
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
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    s.combinationSum2(candidates, 8);
    return 0;
}
