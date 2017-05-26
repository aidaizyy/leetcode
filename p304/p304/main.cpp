//
//  main.cpp
//  p304
//
//  Created by 张云尧 on 2017/5/25.
//  Copyright © 2017年 张云尧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct SegmentTreeNode {
    int start;
    int end;
    int sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int x, int y) : start(x), end(y), sum(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    void buildTree(vector<int>& nums) {
        root = buildTree(nums, 0, (int)nums.size() - 1);
    }
    
    void updateValue(int pos, int val) {
        updateValue(root, pos, val);
    }
    
    int getSum(int start, int end) {
        return getSum(root, start, end);
    }
    
private:
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        else {
            SegmentTreeNode* root = new SegmentTreeNode(start, end);
            if (start == end)
                root->sum = nums[start];
            else {
                int mid = start + (end - start) / 2;
                root->left = buildTree(nums, start, mid);
                root->right = buildTree(nums, mid + 1, end);
                root->sum = root->left->sum + root->right->sum;
            }
            return root;
        }
    }
    
    void updateValue(SegmentTreeNode* root, int pos, int val) {
        if (root->start == root->end) {
            root->sum = val;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (pos <= mid) {
                updateValue(root->left, pos, val);
            } else {
                updateValue(root->right, pos, val);
            }
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
    int getSum(SegmentTreeNode* root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->sum;
        } else {
            int mid = root->start + (root->end - root->start) / 2;
            if (end <= mid)
                return getSum(root->left, start, end);
            else if (start >= mid + 1)
                return getSum(root->right, start, end);
            else
                return getSum(root->left, start, mid) + getSum(root->right, mid + 1, end);
        }
    }
    
    SegmentTreeNode* root;
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        tree.buildTree(nums);
    }
    
    void update(int i, int val) {
        tree.updateValue(i, val);
    }
    
    int sumRange(int i, int j) {
        return tree.getSum(i, j);
    }
    
    SegmentTree tree;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
