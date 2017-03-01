//
//  main.cpp
//  p12
//
//  Created by 张云尧 on 2017/3/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    //46ms
    string intToRoman(int num) {
        string res = "";
        char ch[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        for (int i=0,tmp=1000,pos=0; tmp!=0; ++i,++pos,tmp/=10) {
            if (num / tmp == 4) {
                res += ch[pos*2];
                res += ch[pos*2-1];
                num -= 4 * tmp;
            } else if (num / tmp == 9) {
                res += ch[pos*2];
                res += ch[pos*2-2];
                num -= 9 * tmp;
            }
            if (num / tmp >= 5) {
                res += ch[pos*2-1];
                num -= 5 * tmp;
            }
            while (num / tmp) {
                res += ch[pos*2];
                num -= tmp;
            }
        }
        return res;
    }
    
    /*
    //58ms
    string intToRoman(int num) {
        string res = "";
        int pos = 1;
        while (num > 0) {
            res = func(num%10, pos++) + res;
            num /= 10;
        }
        return res;
    }
    string func(int num, int pos) {
        string s = "";
        char c[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        switch(num) {
            case 1:
                s += c[pos*2-2];
                break;
            case 2:
                s += c[pos*2-2];
                s += c[pos*2-2];
                break;
            case 3:
                s += c[pos*2-2];
                s += c[pos*2-2];
                s += c[pos*2-2];
                break;
            case 4:
                s += c[pos*2-2];
                s += c[pos*2-1];
                break;
            case 5:
                s += c[pos*2-1];
                break;
            case 6:
                s += c[pos*2-1];
                s += c[pos*2-2];
                break;
            case 7:
                s += c[pos*2-1];
                s += c[pos*2-2];
                s += c[pos*2-2];
                break;
            case 8:
                s += c[pos*2-1];
                s += c[pos*2-2];
                s += c[pos*2-2];
                s += c[pos*2-2];
                break;
            case 9:
                s += c[pos*2-2];
                s += c[pos*2];
                break;
            case 10:
                s += c[pos*2];
                break;
            default:
                break;
        }
        return s;
    }
    */
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.intToRoman(3999) << endl;
    return 0;
}
