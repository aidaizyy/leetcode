//
//  main.cpp
//  p372
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;
        int res = 1;
        for (int i = 0; i < b.size()-1; ++i) {
            res *= pow(a, b[i]);
            res %= 1337;
            res = pow(res, 10);
            res %= 1337;
        }
        res *= pow(a, b[b.size()-1]);
        res %= 1337;
        return res;
        
    }
    int pow(int a, int b) {
        a %= 1337;
        if (b == 0)
            return 1;
        int tmp = 1;
        while (b != 1) {
            if (b % 2 == 1) {
                tmp *= a;
                tmp %= 1337;
            }
            a *= a;
            a %= 1337;
            b /= 2;
        }
        a *= tmp;
        a %= 1337;
        return a;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> b = {2, 0, 0};
    cout << s.superPow(2147483647, b) << endl;
    return 0;
}
