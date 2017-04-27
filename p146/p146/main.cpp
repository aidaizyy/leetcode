//
//  main.cpp
//  p146
//
//  Created by 张云尧 on 2017/4/27.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator it = cache.find(key);
        if (it != cache.end())
            touch(it);
        else {
            if (cache.size() == capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
private:
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
    
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> used;
    int capacity;
};

int main(int argc, const char * argv[]) {
    LRUCache lru(0);
    return 0;
}
