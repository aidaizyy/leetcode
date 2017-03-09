//
//  main.cpp
//  p60
//
//  Created by 张云尧 on 2017/3/9.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        vector<bool> flag(n+1, false);
        --k;
        int m = 1;
        for (int i=1; i<n; ++i)
            m *= i;
        for (int i=n-1; i>0; --i) {
            int j = 0;
            for (int t=k/m; t>=0; --t) {
                if (flag[++j]) {
                    ++t;
                    continue;
                }
            }
            flag[j] = true;
            res += '0' + j;
            k %= m;
            m /= i;
        }
        for (int i=1; i<=n; ++i) {
            if (!flag[i]) {
                res += '0' + i;
                break;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getPermutation(1, 1) << endl;
    cout << s.getPermutation(3, 1) << endl;
    cout << s.getPermutation(3, 2) << endl;
    cout << s.getPermutation(3, 3) << endl;
    cout << s.getPermutation(3, 4) << endl;
    cout << s.getPermutation(3, 5) << endl;
    cout << s.getPermutation(3, 6) << endl;
    return 0;
}
