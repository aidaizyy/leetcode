//
//  main.cpp
//  p295
//
//  Created by 张云尧 on 2017/5/22.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }
    
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main(int argc, const char * argv[]) {
    MedianFinder m;
    return 0;
}
