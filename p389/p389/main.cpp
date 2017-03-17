//
//  main.cpp
//  p389
//
//  Created by 张云尧 on 2017/3/17.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        long long sums = 0;
        long long sumt = 0;
        for (char c : s)
            sums += c - 'a';
        for (char c : t)
            sumt += c - 'a';
        return sumt - sums + 'a';
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
