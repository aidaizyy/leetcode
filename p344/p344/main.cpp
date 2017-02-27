//
//  main.cpp
//  p344
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        
        /*
         reverse(s.begin(), s.end());
         return s;
         */
        
        int size = (int)s.size();
        for (int i=0; i<size/2; ++i) {
            swap(s[i], s[size-i-1]);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.reverseString("hello") << endl;
    return 0;
}
