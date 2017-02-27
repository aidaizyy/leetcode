//
//  main.cpp
//  p67
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        /*
        //3ms
        string res;
        size_t sizeA = a.size();
        size_t sizeB = b.size();
        if (sizeA >= sizeB) {
            for (size_t index = 1; index <= sizeB; ++index) {
                a[sizeA - index] += (b[sizeB - index] - '0');
            }
            for (size_t index = sizeA-1; index > 0; --index) {
                if (a[index] >= '2') {
                    a[index] -= 2;
                    a[index-1] += 1;
                }
            }
            if (a[0] >= '2') {
                a[0] -= 2;
                res = "1" + a;
            } else {
                res = a;
            }
        } else {
            for (size_t index = 1; index <= sizeA; ++index) {
                b[sizeB - index] += (a[sizeA - index] - '0');
            }
            for (size_t index = sizeB-1; index > 0; --index) {
                if (b[index] >= '2') {
                    b[index] -= 2;
                    b[index-1] += 1;
                }
            }
            if (b[0] >= '2') {
                b[0] -= 2;
                res = "1" + b;
            } else {
                res = b;
            }
        }
        return res;
        */
        
        //3ms
        string res = "";
        int m = (int)a.size();
        int n = (int)b.size();
        char ch, next = 0;
        while (m > 0 && n > 0) {
            ch = (a[--m] - '0') + (b[--n] - '0') + next;
            next = 0;
            if (ch >= 2) {
                ch -= 2;
                next = 1;
            }
            res += ch + '0';
        }
        while (m > 0) {
            ch = (a[--m] - '0') + next;
            next = 0;
            if (ch >= 2) {
                ch -= 2;
                next = 1;
            }
            res += ch + '0';
        }
        while (n > 0) {
            ch = (b[--n] - '0') + next;
            next = 0;
            if (ch >= 2) {
                ch -= 2;
                next = 1;
            }
            res += ch + '0';
        }
        if (next == 1)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.addBinary("1010", "1011") << endl;
    return 0;
}
