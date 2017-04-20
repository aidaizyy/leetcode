//
//  main.cpp
//  p131
//
//  Created by 张云尧 on 2017/4/21.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    /*
    //13ms
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> item;
        partition(s, 0, item, res);
        return res;
    }
    void partition(string s, int start, vector<string>& item, vector<vector<string>>& res) {
        if (start == s.size())
            res.push_back(item);
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                string str = s.substr(start, i - start + 1);
                item.push_back(str);
                partition(s, i + 1, item, res);
                item.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right) {
        if (left == right)
            return true;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
    */
    
    //6ms
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> item;
        int n = (int)s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
                isPalindrome[i - j][i + j] = true;
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j)
                isPalindrome[i - j][i + j + 1] = true;
        }
        partition(s, 0, isPalindrome, item, res);
        return res;
    }
    void partition(string s, int start, vector<vector<bool>>& isPalindrome, vector<string>& item, vector<vector<string>>& res) {
        if (start == s.size())
            res.push_back(item);
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome[start][i]) {
                string str = s.substr(start, i - start + 1);
                item.push_back(str);
                partition(s, i + 1, isPalindrome, item, res);
                item.pop_back();
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
