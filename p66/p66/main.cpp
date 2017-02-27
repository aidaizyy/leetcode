//
//  main.cpp
//  p66
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = (int)digits.size();
        vector<int> res = digits;
        res[size-1] += 1;
        for (int i=size-1; i>=1; --i) {
            if (res[i] >= 10) {
                res[i] -= 10;
                ++res[i-1];
            }
        }
        if (res[0] >= 10) {
            res[0] -= 10;
            res.push_back(0);
            for (int i=size-1; i>=0; --i) {
                res[i+1] = res[i];
            }
            ++res[0];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> digits1 = {9, 1, 9, 3};
    vector<int> digits2 = {1, 2, 3};
    s.plusOne(digits1);
    s.plusOne(digits2);
    return 0;
}
