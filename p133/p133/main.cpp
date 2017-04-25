//
//  main.cpp
//  p133
//
//  Created by 张云尧 on 2017/4/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;
        UndirectedGraphNode* res;
        unordered_map<int, UndirectedGraphNode*> map;
        UndirectedGraphNode* now = new UndirectedGraphNode(node->label);
        map[node->label] = now;
        res = now;
        queue<UndirectedGraphNode*> que1, que2;
        que1.push(now);
        que2.push(node);
        while (!que2.empty()) {
            now = que1.front();
            que1.pop();
            node = que2.front();
            que2.pop();
            for (int i = 0; i < node->neighbors.size(); ++i) {
                if (map.find(node->neighbors[i]->label) == map.end()) {
                    now->neighbors.push_back(new UndirectedGraphNode(node->neighbors[i]->label));
                    map[node->neighbors[i]->label] = now->neighbors[i];
                    que1.push(now->neighbors[i]);
                    que2.push(node->neighbors[i]);
                } else {
                    now->neighbors.push_back(map[node->neighbors[i]->label]);
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(new UndirectedGraphNode(1));
    node->neighbors[0]->neighbors.push_back(new UndirectedGraphNode(2));
    node->neighbors[0]->neighbors[0]->neighbors.push_back(node->neighbors[0]->neighbors[0]);
    s.cloneGraph(node);
    return 0;
}
