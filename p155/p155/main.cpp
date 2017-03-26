//
//  main.cpp
//  p155
//
//  Created by 张云尧 on 2017/3/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
//29ms
class MinStack {
public:
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        v.push_back(x);
        if (x < min)
            min = x;
    }
    
    void pop() {
        if (v.back() == min) {
            int size = (int)v.size();
            min = INT_MAX;
            for (int i = 0; i< size - 1; ++i) {
                if (v[i] < min)
                    min = v[i];
            }
        }
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return min;
    }
    
private:
    vector<int> v;
    int min;
};
*/

//26ms
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (min.empty() || min.top() >= x)
            min.push(x);
    }
    
    void pop() {
        if (st.top() == min.top())
            min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
    
private:
    stack<int> st;
    stack<int> min;
};

int main(int argc, const char * argv[]) {
    return 0;
}
