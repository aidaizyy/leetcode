//
//  main.cpp
//  p17
//
//  Created by 张云尧 on 2017/3/8.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int map[10][5] = {{0}, {0}, {3, 'a', 'b', 'c'}, {3, 'd', 'e', 'f'},
            {3, 'g', 'h', 'i'}, {3, 'j', 'k', 'l'}, {3, 'm', 'n', 'o'},
            {4, 'p', 'q', 'r', 's'}, {3, 't', 'u', 'v'}, {4, 'w', 'x', 'y', 'z'}};
        queue<string> queue;
        queue.push(string(""));
        for (int i=0; i<digits.size(); ++i) {
            int n = (int)queue.size();
            for (int j=0; j<n; ++j) {
                string str = queue.front();
                for (int k=1; k<=map[digits[i]-'0'][0]; ++k) {
                    queue.push(str+(char)map[digits[i]-'0'][k]);
                }
                queue.pop();
            }
        }
        if (queue.front() == "")
            queue.pop();
        int n = (int)queue.size();
        for (int i=0; i<n; ++i) {
            res.push_back(queue.front());
            cout << queue.front() << endl;
            queue.pop();
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.letterCombinations("2");
    return 0;
}
