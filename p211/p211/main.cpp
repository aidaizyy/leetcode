//
//  main.cpp
//  p211
//
//  Created by 张云尧 on 2017/5/3.
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

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node->next[word[i] - 'a'] == nullptr) {
                node->next[word[i] - 'a'] = new TrieNode();
            }
            node = node->next[word[i] - 'a'];
        }
        node->exist = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }
    
private:
    TrieNode* root;
    bool search(string word, TrieNode* root) {
        TrieNode* node;
        char ch = word[0];
        if (ch != '.') {
            if (root->next[ch - 'a'] == nullptr)
                return false;
            node = root->next[ch - 'a'];
            if (word.size() > 1)
                return search(word.substr(1, word.size() - 1), node);
            return node->exist;
        } else {
            for (int i = 0; i < 26; ++i) {
                if (root->next[i] == nullptr)
                    continue;
                node = root->next[i];
                if (word.size() > 1 && search(word.substr(1, word.size() - 1), node))
                    return true;
                else if (word.size() == 1 && node->exist)
                    return true;
            }
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    WordDictionary w;
    return 0;
}
