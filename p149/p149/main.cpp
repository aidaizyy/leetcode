//
//  main.cpp
//  p149
//
//  Created by 张云尧 on 2017/4/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        typedef long double ld;
        if (points.size() == 0)
            return 0;
        int res = 0;
        int xez = 0, add = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<ld, int> map;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if (x == 0 && y == 0) {
                    ++add;
                    continue;
                }
                if (x == 0) {
                    ++xez;
                    if (y == 0) {
                        ++map[0];
                    }
                } else {
                    ld key = (ld)y / x;
                    ++map[key];
                }
            }
            for (auto it = map.begin(); it != map.end(); ++it)
                res = max(res, it->second + add);
            res = max(res, xez + add);
            xez = 0;
            add = 0;
        }
        return res + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
