//
//  main.cpp
//  p347
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& p, const pair<int, int>& q) {
        return p.second < q.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for (int num : nums)
            ++mymap[num];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> myheap;
        for (auto p : mymap)
            myheap.push(p);
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(myheap.top().first);
            myheap.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
