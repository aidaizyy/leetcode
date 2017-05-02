//
//  main.cpp
//  p210
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
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<unordered_set<int>> graph(numCourses);
        for (auto p : prerequisites)
            graph[p.second].insert(p.first);
        vector<int> degrees(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            for (auto j : graph[i])
                ++degrees[j];
        }
        queue<int> myque;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0)
                myque.push(i);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (myque.empty())
                return vector<int>{};
            int top = myque.front();
            myque.pop();
            res.push_back(top);
            for (auto j : graph[top]) {
                --degrees[j];
                if (degrees[j] == 0)
                    myque.push(j);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
