//
//  main.cpp
//  p165
//
//  Created by 张云尧 on 2017/4/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string::size_type pos;
        size_t base = 0;
        version1 += ".";
        pos = version1.find(".");
        while (pos != string::npos) {
            int num = 0;
            for (size_t i = base; i < pos; ++i) {
                num *= 10;
                num += version1[i] - '0';
            }
            v1.push_back(num);
            base = pos + 1;
            pos = version1.find(".", base);
        }
        base = 0;
        version2 += ".";
        pos = version2.find(".");
        while (pos != string::npos) {
            int num = 0;
            for (size_t i = base; i < pos; ++i) {
                num *= 10;
                num += version2[i] - '0';
            }
            v2.push_back(num);
            base = pos + 1;
            pos = version2.find(".", base);
        }
        size_t size = (int)max(v1.size(), v2.size());
        for (size_t i = v1.size(); i < size; ++i)
            v1.push_back(0);
        for (size_t i = v2.size(); i < size; ++i)
            v2.push_back(0);
        for (size_t i = 0; i < size; ++i) {
            if (v1[i] < v2[i])
                return -1;
            else if (v1[i] > v2[i])
                return 1;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
