//
//  main.cpp
//  p167
//
//  Created by 张云尧 on 2017/2/20.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int size = (int)numbers.size();
        int value1 = 0, value2 = 0;
        for (int i=0; i<size; ++i) {
            int left = i + 1;
            int right = size - 1;
            while (left <= right) {
                int j = (left + right)/2;
                if (numbers[i] + numbers[j] == target) {
                    value1 = numbers[i];
                    value2 = numbers[j];
                    break;
                } else if (numbers[i] + numbers[j] < target) {
                    left = j + 1;
                } else {
                    right = j - 1;
                }
            }
        }
        for (int i=0; i<size; ++i) {
            if (numbers[i] == value1 || numbers[i] == value2) {
                res.push_back(i+1);
                if (res.size() == 2)
                    break;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> numbers = { 2, 7, 11, 15};
    vector<int> res = s.twoSum(numbers, 9);
    return 0;
}
