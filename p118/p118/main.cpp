//
//  main.cpp
//  p118
//
//  Created by 张云尧 on 2017/4/14.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> item;
        for (int i = 1; i <= numRows; ++i) {
            item.insert(item.begin(), 1);
            for (int j = 1; j < item.size() - 1; ++j)
                item[j] += item[j + 1];
            res.push_back(item);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
