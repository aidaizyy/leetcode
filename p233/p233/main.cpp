//
//  main.cpp
//  p233
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        if (n <= 0)
            return res;
        vector<int> map(12);
        map[0] = 0;
        for (int i = 1; i < 12; ++i) {
            map[i] = map[i - 1] * 10 + pow(10, i - 1);
        }
        int i = 0;
        int m = 0;
        while (n != 0) {
            int t = n % 10;
            res += t * map[i++];
            if (t > 1)
                res += pow(10, i - 1);
            else if (t == 1)
                res += m + 1;
            n /= 10;
            m += t * pow(10, i - 1);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
