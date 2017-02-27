//
//  main.cpp
//  p278
//
//  Created by 张云尧 on 2017/2/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int pos = left + (right - left) / 2;
            if (isBadVersion(pos))
                right = pos - 1;
            else
                left = pos + 1;
        }
        return left;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.firstBadVersion(2) << endl;
    return 0;
}
