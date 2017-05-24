//
//  main.cpp
//  p299
//
//  Created by 张云尧 on 2017/5/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mymap;
        int bull = 0;
        int cow = 0;
        int i;
        for (i = 0; i < secret.size() && i < guess.size(); ++i) {
            if (secret[i] == guess[i])
                ++bull;
            else
                ++mymap[secret[i]];
        }
        for ( ; i < secret.size(); ++i)
            ++mymap[secret[i]];
        for (int j = 0; j < guess.size(); ++j) {
            if (j < secret.size() && secret[j] == guess[j])
                continue;
            if (mymap.find(guess[j]) != mymap.end() && mymap[guess[j]] != 0) {
                --mymap[guess[j]];
                ++cow;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.getHint("1123", "0111") << endl;
    return 0;
}
