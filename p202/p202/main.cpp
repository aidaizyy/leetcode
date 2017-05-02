//
//  main.cpp
//  p202
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> myset;
        while (1) {
            int m = 0;
            while (n != 0) {
                int t = n % 10;
                m += t * t;
                n /= 10;
            }
            if (m == 1)
                return true;
            if (myset.find(m) != myset.end())
                return false;
            myset.insert(m);
            n = m;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
