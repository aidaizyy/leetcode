//
//  main.cpp
//  p11
//
//  Created by 张云尧 on 2017/3/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int start = 0;
        int end = (int)height.size() - 1;
        while (start < end) {
            int area = min(height[start], height[end]) * (end - start);
            res = max(res, area);
            if (height[start] <= height[end])
                ++start;
            else
                --end;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> height = {2, 1};
    cout << s.maxArea(height) << endl;
    return 0;
}
