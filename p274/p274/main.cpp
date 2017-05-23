//
//  main.cpp
//  p274
//
//  Created by 张云尧 on 2017/5/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= citations.size() - i) {
                return (int)citations.size() - i;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
