//
//  main.cpp
//  p173
//
//  Created by 张云尧 on 2017/3/31.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        findMin(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* min = st.top();
        st.pop();
        if (min->right != nullptr)
            findMin(min->right);
        return min->val;
    }
    
private:
    stack<TreeNode*> st;
    
    void findMin(TreeNode* root) {
        TreeNode* node = root;
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *root;
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next();
    return 0;
}
