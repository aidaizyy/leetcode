//
//  main.cpp
//  p239
//
//  Created by 张云尧 on 2017/3/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //Monotonic Queue
        vector<int> res;
        deque<int> queue;
        if (nums.empty())
            return res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!queue.empty() && queue.front() == i - k)
                queue.pop_front();
            while (!queue.empty() && nums[queue.back()] < nums[i])
                queue.pop_back();
            queue.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[queue.front()]);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
