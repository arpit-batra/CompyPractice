//
//  main.cpp
//  LowestCommonAncestorOfABinaryTree
//
//  Created by Arpit Batra on 09/08/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode *ans;

bool helperFunction(TreeNode *root,int p,int q){
    if(root==nullptr)return false;
    bool a = helperFunction(root->left, p, q);
    bool b = helperFunction(root->right, p, q);
    bool c = root->val == p || root->val == q;
    if((a && b) || (c && a) || (c && b)) {
        ans = root;
        return false;
    }
    return a || b || c;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    ans = nullptr;
    helperFunction(root, p->val, q->val);
    return ans;
}

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    cout << lowestCommonAncestor(root, root->left->right, root->left->right->right)->val << endl;
    return 0;
}
