//
//  main.cpp
//  p449
//
//  Created by 张云尧 on 2017/5/24.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "n";
        string s1 = to_string(root->val);
        string s2 = serialize(root->left);
        string s3 = serialize(root->right);
        return s1 + "m" + s2 + "m" + s3;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string::size_type begin = 0;
        data += "m";
        return deserialize(data, begin);
    }
    
    TreeNode* deserialize(string& data, string::size_type& begin) {
        if (begin == data.size())
            return nullptr;
        string::size_type pos = data.find("m", begin);
        string str = data.substr(begin, pos - begin);
        if (str == "n") {
            begin = ++pos;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(str));
        begin = pos;
        root->left = deserialize(data, ++begin);
        root->right = deserialize(data, begin);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, const char * argv[]) {
    Codec c;
    return 0;
}
