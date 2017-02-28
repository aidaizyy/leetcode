//
//  main.cpp
//  p371
//
//  Created by 张云尧 on 2017/2/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int next = a & b;
            a ^= b;
            b = next << 1;
        }
        return a;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getSum(2, 3) << endl;
    return 0;
}
