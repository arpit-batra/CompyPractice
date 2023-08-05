//
//  main.cpp
//  SymettricTree
//
//  Created by Arpit Batra on 05/08/23.
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

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr)return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}

bool isMirror(TreeNode *leftOne, TreeNode *rightOne){
    if(leftOne==nullptr && rightOne==nullptr)return true;
    if(leftOne==nullptr || rightOne==nullptr)return false;
    if(leftOne->val!=rightOne->val)return false;
    return isMirror(leftOne->left,rightOne->right) && isMirror(leftOne->right, rightOne->left);
}

bool isSymmetric(TreeNode* root) {
    if(root==nullptr)return true;
    if(root->left==nullptr && root->right==nullptr)return true;
    TreeNode* leftOne = root->left;
    TreeNode* rightOne = root->right;
    return isMirror(leftOne,rightOne);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
