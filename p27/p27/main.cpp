//
//  main.cpp
//  p27
//
//  Created by 张云尧 on 2017/2/23.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        /*
        //3ms
        vector<int>::iterator it = nums.begin();
        while (it != nums.end()) {
            if (*it == val) {
                nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
        */
        
        //3ms
        int size = (int)nums.size();
        int pos = 0;
        for (int i=0; i<size; ++i) {
            if (nums[i] != val) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
