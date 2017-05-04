//
//  main.cpp
//  p223
//
//  Created by 张云尧 on 2017/5/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C - A) * (D - B) + (G - E) * (H - F) - (min(C, G) < max(A, E) ? 0 : min(C, G) - max(A, E)) * (min(D, H) < max(B, F) ? 0 : min(D, H) - max(B, F));
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    return 0;
}
