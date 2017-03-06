//
//  main.cpp
//  p43
//
//  Created by 张云尧 on 2017/3/6.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = (int)num1.size();
        int n = (int)num2.size();
        string res(m + n, '\0');
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                res[i+j] += (num2[j] - '0') * (num1[i] - '0');
                if (res[i+j] / 10 > 0) {
                    res[i+j+1] += res[i+j] / 10;
                    res[i+j] %= 10;
                }
            }
        }
        for (int i=0; i<m+n; ++i) {
            res[i] += '0';
        }
        int end = m + n - 1;
        while (res[end] == '0' && end != 0)
            --end;
        res = res.substr(0, end + 1);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.multiply("3876620623801494171"
                       ,"6529364523802684779") << endl;
    return 0;
}
