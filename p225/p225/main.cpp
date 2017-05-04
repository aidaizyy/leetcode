//
//  main.cpp
//  p225
//
//  Created by 张云尧 on 2017/5/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myque.push(x);
        int n = (int)myque.size();
        for (int i = 0; i < n - 1; ++i) {
            myque.push(myque.front());
            myque.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = myque.front();
        myque.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return myque.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myque.empty();
    }
    
private:
    queue<int> myque;
};

int main(int argc, const char * argv[]) {
    MyStack s;
    return 0;
}
