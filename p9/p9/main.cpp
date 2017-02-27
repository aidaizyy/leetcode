//
//  main.cpp
//  p9
//
//  Created by 张云尧 on 2017/2/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        int y = 0;
        if (x % 10 == 0 && x != 0)
            return false;
        while (x > y) {
            y *= 10;
            y += x % 10;
            if (x == y)
                break;
            x /= 10;
        }
        if (x == y)
            return true;
        else
            return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    std::cout << s.isPalindrome(9229) << std::endl;
    return 0;
}
