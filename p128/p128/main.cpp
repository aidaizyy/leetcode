//
//  main.cpp
//  p128
//
//  Created by 张云尧 on 2017/4/18.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    /*
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        vector<int> parent(nums.size(), -1);
        vector<int> rank(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
                parent[i] = i;
                rank[i] = 1;
                if (map.find(nums[i] - 1) != map.end()) {
                    int tmp = getParent(parent, parent[map[nums[i] - 1]]);
                    parent[tmp] = i;
                    rank[i] += rank[tmp];
                }
                if (map.find(nums[i] + 1) != map.end()) {
                    int tmp = getParent(parent, parent[map[nums[i] + 1]]);
                    parent[tmp] = i;
                    rank[i] += rank[tmp];
                }
                res = max(res, rank[i]);
            }
        }
        return res;
    }
    int getParent(vector<int>& parent, int x) {
        int t = x;
        while (parent[t] != t) {
            t = parent[t];
        }
        int p = t;
        while (parent[x] != x) {
            t = parent[x];
            parent[x] = p;
            x = t;
        }
        return p;
    }
    */
    
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> map;
        for (int num : nums) {
            if (map.find(num) == map.end()) {
                int left = map.find(num - 1) != map.end() ? map[num - 1] : 0;
                int right = map.find(num + 1) != map.end() ? map[num + 1] : 0;
                map[num] = left + right + 1;
                map[num - left] = map[num];
                map[num + right] = map[num];
                res = max(res, map[num]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1,3,5,2,4};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}
