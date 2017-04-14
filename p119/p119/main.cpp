//
//  main.cpp
//  p119
//
//  Created by 张云尧 on 2017/4/14.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for (int i = 0; i <= rowIndex; ++i) {
            res.insert(res.begin(), 1);
            for (int j = 1; j < res.size() - 1; ++j)
                res[j] += res[j + 1];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
