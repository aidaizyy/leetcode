//
//  main.cpp
//  p310
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return vector<int>({0});
        vector<unordered_set<int>> graph(n);
        for (auto p : edges) {
            graph[p.second].insert(p.first);
            graph[p.first].insert(p.second);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i)
            if (graph[i].size() == 1)
                leaves.push_back(i);
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                for (int j : graph[i]) {
                    graph[j].erase(i);
                    if (graph[j].size() == 1)
                        newLeaves.push_back(j);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<pair<int, int>> edges = {make_pair(1, 0), make_pair(1, 2), make_pair(1,3)};
    s.findMinHeightTrees(4, edges);
    return 0;
}
