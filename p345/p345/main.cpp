//
//  main.cpp
//  p345
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'A' ||
            ch == 'E' || ch == 'I' || ch == 'O' ||
            ch == 'U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = (int)s.size() - 1;
        while (i < j) {
            while (!isVowel(s[i]))
                ++i;
            while (!isVowel(s[j]))
                --j;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverseVowels("leetcode") << endl;
    return 0;
}
