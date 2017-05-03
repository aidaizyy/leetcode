//
//  main.cpp
//  p451
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(const pair<char, int>& p, const pair<char, int>& q) {
        return p.second < q.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        for (char ch : s)
            ++mymap[ch];
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> myheap;
        for (auto p : mymap)
            myheap.push(p);
        string res = "";
        while (!myheap.empty()) {
            res.append(myheap.top().second, myheap.top().first);
            myheap.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
