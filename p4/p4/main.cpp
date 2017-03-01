//
//  main.cpp
//  p4
//
//  Created by 张云尧 on 2017/3/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int k = (m + n + 1) / 2;
        int i = 0, j = 0;
        while (k != 1 && m - i != 0 && n - j != 0 ) {
            if (m - i > k / 2 && n - j > k / 2) {
                if (nums1[i+k/2-1] <= nums2[j+k/2-1])
                    i += k / 2;
                else
                    j += k / 2;
                k -= k / 2;
            } else if (m - i < n - j) {
                k -= m - i;
                if (nums1[i+m-i-1] <= nums2[j+m-i-1])
                    i += m - i;
                else
                    j += m - i;
            } else {
                k -= n - j;
                if (nums1[i+n-j-1] <= nums2[j+n-j-1])
                    i += n - j;
                else
                    j += n - j;
            }
        }
        if (m - i == 0) {
            if ((m + n) % 2 == 1)
                return (double)nums2[j+k-1];
            else
                return ((double)nums2[j+k-1] + ((double)nums2[j+k])) / 2;
        }
        else if (n - j == 0) {
            if ((m + n) % 2 == 1)
                return (double)nums1[i+k-1];
            else
                return ((double)nums1[i+k-1] + ((double)nums1[i+k])) / 2;
        }
        else {
            if ((m + n) % 2 == 1)
                return min((double)nums1[i+k-1], (double)nums2[j+k-1]);
            else {
                double res1, res2;
                if (nums1[i] < nums2[j]) {
                    res1 = (double)nums1[i];
                    if (i+1 != m)
                        res2 = min((double)nums1[i+1], (double)nums2[j]);
                    else
                        res2 = (double)nums2[j];
                    return (res1 + res2) / 2;
                } else if (nums1[i] > nums2[j]) {
                    res1 = (double)nums2[j];
                    if (j+1 != n)
                        res2 = min((double)nums1[i], (double)nums2[j+1]);
                    else
                        res2 = (double)nums1[i];
                    return (res1 + res2) / 2;
                } else
                    return (double)nums1[i];
            }
        }
        return 0;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {1, 3, 4};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
