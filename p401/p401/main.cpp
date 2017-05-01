//
//  main.cpp
//  p401
//
//  Created by 张云尧 on 2017/5/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                int now = 0;
                int hour = i;
                while (hour != 0) {
                    hour &= hour - 1;
                    ++now;
                }
                int minute = j;
                while (minute != 0) {
                    minute &= minute - 1;
                    ++now;
                }
                if (now == num) {
                    string str = to_string(j);
                    if (str.size() == 1)
                        str = "0" + str;
                    str = to_string(i) + ":" + str;
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
