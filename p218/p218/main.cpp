//
//  main.cpp
//  p218
//
//  Created by 张云尧 on 2017/5/15.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
    public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myque;
        multiset<int> myset;
        int maxv = 0;
        for (vector<int> b : buildings) {
            while (!myque.empty() && myque.top().first < b[0]) {
                myset.erase(myset.lower_bound(myque.top().second));
                if (myset.empty())
                    addOne(res, myque.top().first, 0);
                else if (maxv != *myset.rbegin()) {
                    addOne(res, myque.top().first, *myset.rbegin());
                    maxv = *myset.rbegin();
                }
                myque.pop();
            }
            myque.push(make_pair(b[1], b[2]));
            myset.insert(b[2]);
            if (maxv != *myset.rbegin()) {
                addOne(res, b[0], b[2]);
                maxv = *myset.rbegin();
            }
        }
        while (!myque.empty()) {
            myset.erase(myset.lower_bound(myque.top().second));
            if (myset.empty())
                addOne(res, myque.top().first, 0);
            else if (maxv != *myset.rbegin()) {
                addOne(res, myque.top().first, *myset.rbegin());
                maxv = *myset.rbegin();
            }
            myque.pop();
        }
        return res;
    }
    void addOne(vector<pair<int, int>>& res, int x, int y) {
        if (!res.empty() && res.back().first == x)
            res.back().second = y;
        else
            res.push_back(make_pair(x, y));
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    s.getSkyline(buildings);
    return 0;
}
