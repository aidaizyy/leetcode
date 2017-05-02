//
//  main.cpp
//  p207
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    
    /*
    //126ms
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto p : prerequisites)
            graph[p.second].insert(p.first);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && existCycle(graph, i, visited))
                return false;
        }
        return true;
    }
    bool existCycle(vector<unordered_set<int>>& graph, int i, vector<bool>& visited) {
        if (visited[i])
            return false;
        visited[i] = true;
        for (auto j : graph[i]) {
            if (visited[j] || existCycle(graph, j, visited))
                return true;
        }
        visited[i] = false;
        return false;
    }
    */
    
    //16ms
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto p : prerequisites)
            graph[p.second].insert(p.first);
        vector<int> degrees(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            for (auto j : graph[i])
                ++degrees[j];
        }
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for ( ; j < numCourses; ++j)
                if (degrees[j] == 0)
                    break;
            if (j == numCourses)
                return false;
            degrees[j] = -1;
            for (auto k : graph[j])
                --degrees[k];
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
