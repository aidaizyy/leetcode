//
//  main.cpp
//  p6
//
//  Created by 张云尧 on 2017/3/1.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string res = "";
        int size = (int)s.size();
        for (int i=0; i<numRows; ++i) {
            for (int j=0; i+j<size; j += 2*numRows-2) {
                res += s[i+j];
                if (i != 0 && i != numRows-1) {
                    int k = i + j + 2 * (numRows - i - 1);
                    if (k < size)
                        res += s[k];
                }
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.convert("A", 1) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
