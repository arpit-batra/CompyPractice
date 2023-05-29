//
//  main.cpp
//  BinaryTreeInorderTraversal
//
//  Created by Arpit Batra on 22/04/23.
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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    if(root==nullptr)return ans;
    if(root->left!=nullptr){
        vector<int>leftInorder = inorderTraversal(root->left);
        ans.insert(ans.end(), leftInorder.begin(),leftInorder.end());
    }
    ans.push_back(root->val);
    if(root->right!=nullptr){
        vector<int>rightInorder = inorderTraversal(root->right);
        ans.insert(ans.end(), rightInorder.begin(),rightInorder.end());
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    TreeNode input;
    
    return 0;
}
