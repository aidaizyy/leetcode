//
//  main.cpp
//  p88
//
//  Created by 张云尧 on 2017/2/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        /*
        //3ms
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        while (m > 0 && n >0) {
            if (*it1 > *it2) {
                nums1.pop_back();
                nums1.insert(it1++, *it2++);
                --n;
            } else {
                ++it1;
                --m;
            }
        }
        while (n-- > 0) {
            nums1.pop_back();
            nums1.insert(it1++, *it2++);
        }
        */
        
        //3ms
        int i = 0, j = 0;
        while (j < n && i < m) {
            if (nums1[i] > nums2[j]) {
                for (int k=m-1; k>=i; --k) {
                    nums1[k+1] = nums1[k];
                }
                nums1[i] = nums2[j];
                ++m;
                ++i;
                ++j;
            } else {
                ++i;
            }
        }
        while (j < n) {
            nums1[i++] = nums2[j++];
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3};
    s.merge(nums1, 3, nums2, 3);
}
