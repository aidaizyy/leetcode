//
//  main.cpp
//  p273
//
//  Created by 张云尧 on 2017/5/16.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        vector<string> numStr = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> numStr2 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> numStr3 = {"Hundred", "Thousand", "Million", "Billion"};
        if (num == 0)
            return numStr[0];
        string res = "";
        for (int i = 0; i < 3; ++i) {
            if (num == 0)
                break;
            string tmpStr = "";
            int tmp = num % 1000;
            if (tmp == 0) {
                num /= 1000;
                continue;
            }
            if (tmp / 100 != 0) {
                tmpStr += numStr[tmp / 100];
                tmpStr += " ";
                tmpStr += numStr3[0];
                tmpStr += " ";
            }
            tmp %= 100;
            if (tmp / 10 != 0 && tmp / 10 != 1) {
                tmpStr += numStr2[tmp / 10 - 2];
                tmpStr += " ";
                tmp %= 10;
                if (tmp != 0) {
                    tmpStr += numStr[tmp];
                    tmpStr += " ";
                }
            } else if (tmp / 10 != 0) {
                tmp %= 10;
                tmpStr += numStr[tmp + 10];
                tmpStr += " ";
            } else {
                tmp %= 10;
                if (tmp != 0) {
                    tmpStr += numStr[tmp];
                    tmpStr += " ";
                }
            }
            if (i == 1) {
                tmpStr += numStr3[1];
                tmpStr += " ";
            } else if (i == 2) {
                tmpStr += numStr3[2];
                tmpStr += " ";
            }
            res = tmpStr + res;
            num /= 1000;
        }
        if (num != 0) {
            string tmpStr = "";
            tmpStr += numStr[num];
            tmpStr += " ";
            tmpStr += numStr3[3];
            tmpStr += " ";
            res = tmpStr + res;
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
