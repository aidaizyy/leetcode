//
//  main.cpp
//  p452
//
//  Created by 张云尧 on 2017/4/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(const pair<int, int> x, const pair<int, int> y) {
        return x.second < y.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        
        /*
        //262ms
        sort(points.begin(), points.end(), compare);
        vector<bool> isShot(points.size(), false);
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (isShot[i])
                continue;
            ++res;
            for (int j = i; j < points.size(); ++j) {
                if (points[j].first <= points[i].second)
                    isShot[j] = true;
            }
        }
        return res;
        */
        
        //89ms
        sort(points.begin(), points.end(), compare);
        if (points.size() == 0)
            return 0;
        int res = 1;
        int end = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i].first <= end)
                continue;
            ++res;
            end = points[i].second;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
