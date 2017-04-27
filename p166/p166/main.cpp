//
//  main.cpp
//  p166
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string res = "";
        if (numerator < 0 ^ denominator < 0)
            res += '-';
        typedef unsigned long long ull;
        ull n = abs((long long)numerator);
        ull d = abs((long long)denominator);
        res += to_string(n / d);
        if (n % d == 0)
            return res;
        res += '.';
        unordered_map<ull, ull> map;
        for (ull i = n % d; i; i %= d) {
            if (map.find(i) != map.end()) {
                res.insert(map[i], "(");
                res += ')';
                break;
            }
            map[i] = res.size();
            i *= 10;
            res += to_string(i / d);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
