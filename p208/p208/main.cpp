//
//  main.cpp
//  p208
//
//  Created by 张云尧 on 2017/5/2.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
using namespace std;

struct TrieNode{
    bool exist;
    TrieNode* next[26];
    TrieNode() : exist(0) {
        memset(next, 0, sizeof(next));
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->next[word[i] - 'a'] == nullptr) {
                node->next[word[i] - 'a'] = new TrieNode();
            }
            node = node->next[word[i] - 'a'];
        }
        node->exist = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->next[word[i] - 'a'] == nullptr)
                return false;
            node = node->next[word[i] - 'a'];
        }
        return node->exist;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (node->next[prefix[i] - 'a'] == nullptr)
                return false;
            node = node->next[prefix[i] - 'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

int main(int argc, const char * argv[]) {
    Trie* t = new Trie();
    t->insert("ab");
    return 0;
}
