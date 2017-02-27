//
//  main.cpp
//  p374
//
//  Created by 张云尧 on 2017/2/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int num = left + (right - left) / 2;
            int res = guess(num);
            if (res == 0)
                return num;
            else if (res == 1)
                left = num + 1;
            else
                right = num - 1;
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.guessNumber(2) << endl;
    return 0;
}
