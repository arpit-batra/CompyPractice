//
//  main.cpp
//  PopulatingNextRightPointersInEachNode2
//
//  Created by Arpit Batra on 05/08/23.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *next;
    
    Node():val(0),left(nullptr),right(nullptr),next(nullptr){}
    Node(int x):val(x),left(nullptr),right(nullptr),next(nullptr){}
    Node(int x,Node* left, Node* right,Node* next):val(x),left(left),right(right),next(next){}
};

//void generatePreOrder(TreeNode *root,vector<int>& ans){
//    if(root!=nullptr){
//        ans.push_back(root->val);
//        generatePreOrder(root->left, ans);
//        generatePreOrder(root->right, ans);
//    }
//}
//
//TreeNode* duplicateTree(TreeNode * original){
//    TreeNode* newTree;
//    if(original==nullptr)return nullptr;
//    newTree = new TreeNode(original->val, duplicateTree(original->left), duplicateTree(original->right));
//    return newTree;
//}
//
//int maxDepth(TreeNode* root) {
//    if(root==nullptr)return 0;
//    return max(maxDepth(root->left),maxDepth(root->right))+1;
//}
//
//TreeNode* invertTree(TreeNode* root) {
//    if(root==nullptr)return nullptr;
//    TreeNode* temp = root->left;
//    root->left = root->right;
//    root->right = temp;
//    root->left = invertTree(root->left);
//    root->right = invertTree(root->right);
//    return root;
//}
//
//bool isMirror(TreeNode *leftOne, TreeNode *rightOne){
//    if(leftOne==nullptr && rightOne==nullptr)return true;
//    if(leftOne==nullptr || rightOne==nullptr)return false;
//    if(leftOne->val!=rightOne->val)return false;
//    return isMirror(leftOne->left,rightOne->right) && isMirror(leftOne->right, rightOne->left);
//}
//
//bool isSymmetric(TreeNode* root) {
//    if(root==nullptr)return true;
//    if(root->left==nullptr && root->right==nullptr)return true;
//    TreeNode* leftOne = root->left;
//    TreeNode* rightOne = root->right;
//    return isMirror(leftOne,rightOne);
//}

Node* connect(Node*root){
    if(root==nullptr)return nullptr;
    if(root->left==nullptr && root->right==nullptr)return root;
    if(root->left!=nullptr && root->right!=nullptr){
        root->left->next = root->right;
    }
    if(root->next!=nullptr){
        Node*temp=root->next;
        int flag=0;
//        while(!(temp->left!=nullptr || temp->right!=nullptr)){
            while(temp!=nullptr){
            if(temp->left!=nullptr || temp->right!=nullptr){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1){
            if(root->right==nullptr){
                //connection with root->left
                if(temp->left==nullptr){
                    root->left->next = temp->right;
                }else{
                    root->left->next = temp->left;
                }
            } else{
                //connection with root->right
                if(temp->left==nullptr){
                    root->right->next = temp->right;
                }else{
                    root->right->next = temp->left;
                }
            }
        }
    }
    root->right = connect(root->right);
    root->left = connect(root->left);   
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
