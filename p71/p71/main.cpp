//
//  main.cpp
//  p71
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int pos = 0;
        path += "/";
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                string str = path.substr(pos, i - pos);
                if (str == "..") {
                    if (!st.empty())
                        st.pop();
                } else if (str != "." && str != "")
                    st.push(str);
                pos = i + 1;
            }
        }
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        if (res == "")
            res = "/";
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.simplifyPath("/../") << endl;
    return 0;
}
