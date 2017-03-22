//
//  main.cpp
//  p68
//
//  Created by 张云尧 on 2017/3/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = (int)words.size();
        int i = 0;
        string str = "";
        int count = 0;
        int len = maxWidth;
        while (i != n) {
            if (count == 0) {
                str += words[i];
                ++count;
                len -= words[i++].size();
            } else {
                if (len - 1 >= (int)words[i].size()) {
                    str += " " + words[i];
                    ++count;
                    len -= words[i++].size() + 1;
                } else {
                    if (count == 1) {
                        for (int i = 0; i < len; ++i)
                            str += " ";
                    } else {
                        vector<int> pos(count, 0);
                        for (int j = 1; j < count; ++j)
                            pos[j] = pos[j-1] + words[i-count+j-1].size() + 1;
                        for (int j = 0; j < len; ++j)
                            str.insert(pos[j % (count - 1) + 1] + j % (count - 1) + j / (count - 1), " ");
                    }
                    res.push_back(str);
                    str = "";
                    count = 0;
                    len = maxWidth;
                }
            }
        }
        for (int i = 0; i < len; ++i)
            str += " ";
        res.push_back(str);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    s.fullJustify(words, 16);
    return 0;
}
