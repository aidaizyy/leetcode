//
//  main.cpp
//  p135
//
//  Created by 张云尧 on 2017/4/26.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
//36ms O(logn)
bool cmp(pair<int, int> p, pair<int, int> q) {
    return p.first < q.first;
}

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        if (n == 0 || n == 1)
            return n;
        int res = 0;
        vector<pair<int, int>> mymap;
        for (int i = 0; i < n; ++i)
            mymap.push_back(make_pair(ratings[i], i));
        sort(mymap.begin(), mymap.end(), cmp);
        vector<int> num(n, 0);
        for (vector<pair<int,int>>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
            int pos = it->second;
            if (pos == 0)
                num[pos] = ratings[pos] == ratings[pos + 1] ? 1 : num[pos + 1] + 1;
            else if (pos == n - 1)
                num[pos] = ratings[pos] == ratings[pos - 1] ? 1 : num[pos - 1] + 1;
            else {
                if (ratings[pos] == ratings[pos - 1] && ratings[pos] == ratings[pos + 1])
                    num[pos] = 1;
                else {
                    if (ratings[pos] != ratings[pos - 1])
                        num[pos] = num[pos - 1] + 1;
                    if (ratings[pos] != ratings[pos + 1])
                        num[pos] = max(num[pos], num[pos + 1] + 1);
                }
            }
            res += num[pos];
        }
        return res;
    }
};
*/

//26ms O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> num(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1])
                num[i] = num[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                num[i] = max(num[i], num[i + 1] + 1);
        }
        int res = 0;
        for (int i : num)
            res += i;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> ratings = {2, 3, 2};
    cout << s.candy(ratings) << endl;
    return 0;
}
