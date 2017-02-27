//
//  main.cpp
//  p58
//
//  Created by 张云尧 on 2017/2/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        /*
        //3ms
        int size = (int)s.size();
        int last;
        for (last = size - 1; last>=0; --last) {
            if (s[last] != ' ')
                break;
        }
        s = s.substr(0, last+1);
        return last - s.rfind(' ');
        */
        
        //3ms
        int res = 0;
        int size = (int)s.size();
        int flag = 0;
        for (int i=size-1; i>=0; --i) {
            if (s[i] == ' ' && flag == 1)
                return res;
            else if (s[i] != ' ') {
                flag = 1;
                ++res;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.lengthOfLastWord(" ") << endl;
    return 0;
}
