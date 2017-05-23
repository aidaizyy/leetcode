//
//  main.cpp
//  p275
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
        int size = (int)citations.size();
        int left = 0;
        int right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] > size - mid)
                right = mid - 1;
            else if (citations[mid] < size - mid)
                left = mid + 1;
            else
                return size - mid;
        }
        return size - left;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
