//
//  main.cpp
//  p69
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        /*
        //6ms
        if (x == 0)
            return 0;
        int left = 1;
        int right = INT_MAX;
        while (1) {
            int middle = left + (right - left) / 2;
            if (middle > x / middle)
                right = middle - 1;
            else if (middle + 1 > x / (middle + 1))
                return middle;
            else
                left = middle + 1;
        }
        */
        
        //3ms
        long long l = x;
        while (l * l > x) {
            l = (l + x / l) >> 1;
        }
        return (int)l;
    };
    
int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.mySqrt(4) << endl;
    return 0;
}
