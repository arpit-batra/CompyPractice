//
//  main.cpp
//  MaximumDepthOfBinaryTree
//
//  Created by Arpit Batra on 17/05/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

void generatePreOrder(TreeNode *root,vector<int>& ans){
    if(root!=nullptr){
        ans.push_back(root->val);
        generatePreOrder(root->left, ans);
        generatePreOrder(root->right, ans);
    }
}

TreeNode* duplicateTree(TreeNode * original){
    TreeNode* newTree;
    if(original==nullptr)return nullptr;
    newTree = new TreeNode(original->val, duplicateTree(original->left), duplicateTree(original->right));
    return newTree;
}

int maxDepth(TreeNode* root) {
    if(root==nullptr)return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr && q==nullptr)return true;
    if(p==nullptr || q==nullptr)return false;
    if(p->val!=q->val)return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
}

int main(int argc, const char * argv[]) {
    int n;
    while(true){
        cout << "Enter length of array\n";
        cin >> n;
        vector<int>input(n);
        for(int i=0;i<n;i++){
            cin >>input[i];
        }
    }
    return 0;
    }
