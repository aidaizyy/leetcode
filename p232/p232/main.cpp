//
//  main.cpp
//  p232
//
//  Created by 张云尧 on 2017/5/4.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!mystack.empty()) {
            tmp.push(mystack.top());
            mystack.pop();
        }
        mystack.push(x);
        while (!tmp.empty()) {
            mystack.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = mystack.top();
        mystack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return mystack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mystack.empty();
    }
    
private:
    stack<int> mystack;
};

int main(int argc, const char * argv[]) {
    MyQueue q;
    return 0;
}
