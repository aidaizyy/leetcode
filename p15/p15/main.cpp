//
//  main.cpp
//  p15
//
//  Created by 张云尧 on 2017/2/28.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        /*
        //322ms
        vector<vector<int>> res;
        int size = (int)nums.size();
        if (size <= 2)
            return res;
        sort(nums.begin(), nums.end());
        int lasti = nums[0] + 1;
        int lastj;
        for (int i=0; i<size; ++i) {
            if (lasti == nums[i])
                continue;
            lasti = nums[i];
            lastj = nums[i+1] + 1;
            for (int j=i+1; j<size; ++j) {
                if (lastj == nums[j])
                    continue;
                lastj = nums[j];
                int left = j + 1;
                int right = size - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    int sum = nums[i] + nums[j] + nums[mid];
                    if (sum == 0) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[mid]});
                        break;
                    } else if (sum < 0) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        return res;
        */
        
        /*
        //182ms
        vector<vector<int>> res;
        if (nums.size() <= 2)
            return res;
        vector<int> n1, n2;
        int size3 = 0;
        for (int num : nums) {
            if (num < 0)
                n1.push_back(num);
            else if (num > 0)
                n2.push_back(num);
            else {
                n1.push_back(num);
                ++size3;
            }
        }
        int size1 = (int)n1.size();
        int size2 = (int)n2.size();
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        
        int lasti, lastj;
        if (size1 >= 2) {
            lasti = n1[0] + 1;
            for (int i=0; i<size1; ++i) {
                if (lasti == n1[i])
                    continue;
                lasti = n1[i];
                lastj = n1[i+1] + 1;
                for (int j=i+1; j<size1; ++j) {
                    if (lastj == n1[j])
                        continue;
                    lastj = n1[j];
                    int target = 0 - n1[i] - n1[j];
                    int left = 0;
                    int right = size2 - 1;
                    while (left <= right) {
                        int mid = left + (right - left) / 2;
                        if (n2[mid] == target) {
                            res.push_back(vector<int>{n1[i], n1[j], n2[mid]});
                            break;
                        } else if (n2[mid] < target) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                }
            }
        }
        
        if (size2 >= 2) {
            lasti = n2[0] + 1;
            for (int i=0; i<size2; ++i) {
                if (lasti == n2[i])
                    continue;
                lasti = n2[i];
                lastj = n2[i+1] + 1;
                for (int j=i+1; j<size2; ++j) {
                    if (lastj == n2[j])
                        continue;
                    lastj = n2[j];
                    int target = 0 - n2[i] - n2[j];
                    int left = 0;
                    int right = size1 - 1;
                    while (left <= right) {
                        int mid = left + (right - left) / 2;
                        if (n1[mid] == target) {
                            res.push_back(vector<int>{n2[i], n2[j], n1[mid]});
                            break;
                        } else if (n1[mid] < target) {
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }
                }
            }
        }
        
        if (size3 >= 3) {
            res.push_back(vector<int>{0, 0, 0});
        }
        
        return res;
        */
        
        //112ms
        vector<vector<int>> res;
        if (nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());
        const int target = 0;
        int size = (int)nums.size();
        for (int i=0; i<size-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    ++left;
                    while (left < right && nums[left] == nums[left-1])
                        ++left;
                } else if (sum > target) {
                    --right;
                    while (left < right && nums[right] == nums[right+1])
                        --right;
                } else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left-1])
                        ++left;
                    while (left < right && nums[right] == nums[right+1])
                        --right;
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, -1, -1, 0};
    s.threeSum(nums);
    return 0;
}































