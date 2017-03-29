//
//  main.cpp
//  p84
//
//  Created by 张云尧 on 2017/3/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        vector<int> index;
        for (int i = 0; i < heights.size(); ++i) {
            while (!index.empty() && heights[i] <= heights[index.back()]) {
                int min = heights[index.back()];
                index.pop_back();
                int beg = -1;
                if (!index.empty())
                    beg = index.back();
                if (res < (i - beg - 1) * min)
                    res= (i - beg - 1) * min;
            }
            index.push_back(i);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> heights = {5,6,1};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
