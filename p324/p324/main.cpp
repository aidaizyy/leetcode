//
//  main.cpp
//  p324
//
//  Created by 张云尧 on 2017/5/3.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        /*
        //O(nlogn)  O(n)
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<int> tmp = nums;
        int left = (n - 1) / 2;
        int right = n - 1;
        for (int i = 0; i < n; ++i) {
            if ((i & 1) == 0)
                nums[i] = tmp[left--];
            else
                nums[i] = tmp[right--];
        }
        */
        
        int n = (int)nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        
        #define A(i) nums[(2 * i + 1) % (n | 1)]
        
        int i = 0;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            if (A(left) > mid)
                swap(A(i++), A(left++));
            else if (A(left) < mid)
                swap(A(left), A(right--));
            else
                ++left;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
