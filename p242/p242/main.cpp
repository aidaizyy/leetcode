//
//  main.cpp
//  p242
//
//  Created by 张云尧 on 2017/3/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    unsigned long long hash(string& s) {
        int sum = 0;
        int pro = 1;
        int XOR = 0;
        for (char c : s) {
            sum += (c * c * c * c);
            pro *= (c * c * c * c);
            XOR ^= (c * c * c * c);
        }
        return sum ^ pro ^ XOR;
    }
    bool isAnagram(string s, string t) {
        return hash(s) == hash(t);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
