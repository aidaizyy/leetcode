//
//  main.cpp
//  p367
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        /*
        //3ms
        if (num == 0)
            return 0;
        int left = 1;
        int right = INT_MAX;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (middle > num / middle)
                right = middle - 1;
            else if (middle * middle== num)
                return true;
            else
                left = middle + 1;
        }
        return false;
        */
        
        /*
        //9ms
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
        */
        
        //0ms
        long long l = num;
        while (l * l > num) {
            l = (l + num / l) >> 1;
        }
        return l * l == num;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
