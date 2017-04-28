//
//  main.cpp
//  p338
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;
        int base = 1;
        bool isContinue = true;
        while (isContinue) {
            for (int i = 0; i < base; ++i) {
                if (i + base > num) {
                    isContinue = false;
                    break;
                }
                res[i + base] = res[i] + 1;
            }
            base *= 2;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.countBits(2);
    return 0;
}
