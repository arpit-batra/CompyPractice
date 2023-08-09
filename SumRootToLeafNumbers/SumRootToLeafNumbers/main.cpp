//
//  main.cpp
//  SumRootToLeafNumbers
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


int ans;
void helperFunction(TreeNode* root, int currValue){
    
    if(root==nullptr)return;
    cout << "root->val  -> " << root->val <<" currValue -> "<<currValue << endl;
    if(root->left == nullptr && root->right == nullptr){
        ans +=((currValue*10)+(root->val));
    }
    helperFunction(root->left,(currValue*10)+(root->val));
    helperFunction(root->right,(currValue*10)+(root->val));
    return;
}


int sumNumbers(TreeNode* root) {
    ans = 0;
    helperFunction(root,0);
    return ans;
}


int main(int argc, const char * argv[]) {
//    TreeNode *root = nullptr;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root) << endl;
}
