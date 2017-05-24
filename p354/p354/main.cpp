//
//  main.cpp
//  p354
//
//  Created by 张云尧 on 2017/5/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool cmp(const pair<int, int>& p, const pair<int, int>& q) {
    if (p.first == q.first)
        return p.second > q.second;
    else
        return p.first < q.first;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> res;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(res.begin(), res.end(), envelopes[i].second);
            if (it == res.end())
                res.push_back(envelopes[i].second);
            else if (envelopes[i].second < *it)
                *it = envelopes[i].second;
        }
        return (int)res.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
