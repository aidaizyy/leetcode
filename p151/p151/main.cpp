//
//  main.cpp
//  p151
//
//  Created by 张云尧 on 2017/4/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        
        /*
        s += " ";
        vector<string> result;
        for (size_t i = 0; i < s.size(); ++i) {
            string::size_type begin = s.find_first_not_of(" ", i);
            if (begin == string::npos)
                break;
            string::size_type end = s.find_first_of(" ", begin);
            string str = s.substr(begin, end - begin);
            result.push_back(str);
            i = end;
        }
        s = "";
        for (auto it = result.rbegin(); it != result.rend(); ++it) {
            s += *it + " ";
        }
        s = s.substr(0, s.size() - 1);
        */
        
        //in-place
        reverse(s.begin(), s.end());
        s += " ";
        bool flag = false;
        int begin = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (flag == false) {
                    flag = true;
                    s[end++] = s[i];
                } else {
                    s[end++] = s[i];
                }
            } else {
                if (flag == true) {
                    reverse(s.begin() + begin, s.begin() + end);
                    s[end] = ' ';
                    ++end;
                    begin = end;
                    flag = false;
                }
            }
        }
        if (end != 0)
            s.erase(s.begin() + end - 1, s.end());
        else
            s = "";
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    string str = " ";
    s.reverseWords(str);
    return 0;
}
