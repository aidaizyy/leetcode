//
//  main.cpp
//  p42
//
//  Created by 张云尧 on 2017/3/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        /*
        9ms
        int res = 0;
        int size = (int)height.size();
        if (size == 0)
            return res;
        int maxleft[size];
        int maxright[size];
        maxleft[0] = 0;
        maxright[size-1] = 0;
        for (int i=1; i<size; ++i) {
            maxleft[i] = max(maxleft[i-1], height[i-1]);
            maxright[size-i-1] = max(maxright[size-i], height[size-i]);
        }
        for (int i=0; i<size; ++i) {
            int tmp = min(maxleft[i], maxright[i]);
            if (tmp > height[i])
                res += tmp - height[i];
        }
        return res;
        */
        
        //9ms
        int res = 0;
        int size = (int)height.size();
        int max = 0;
        for (int i=0; i<size; ++i) {
            if (height[i] > height[max])
                max = i;
        }
        for (int i=0, maxl=0; i<max; ++i) {
            if (height[i] > maxl)
                maxl = height[i];
            else
                res += maxl - height[i];
        }
        for (int i=size-1, maxr=0; i>max; --i) {
            if (height[i] > maxr)
                maxr = height[i];
            else
                res += maxr - height[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> height = {0, 2, 0};
    cout << s.trap(height) << endl;
    return 0;
}
