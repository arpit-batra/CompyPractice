//
//  main.cpp
//  UniqueBinarySearchTrees2
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


void increaseEveryNode(TreeNode *tree, int x){
    if(tree==nullptr)return;
    TreeNode* head = tree;
    tree->val = tree->val+x;
    if(tree->left!=nullptr)increaseEveryNode(tree->left, x);
    if(tree->right!=nullptr)increaseEveryNode(tree->right, x);
    return;
}

void generatePreOrder(TreeNode *root,vector<int>& ans){
    if(root!=nullptr){
        ans.push_back(root->val);
        generatePreOrder(root->left, ans);
        generatePreOrder(root->right, ans);
    }
}

 

TreeNode* generateTreeFromSimpleOrderWithNull(vector<int> input){
    TreeNode* ans;
    if(input.size()==0)return nullptr;
    ans = new TreeNode(input[0]);
    queue<TreeNode*> inserterQueue;
    inserterQueue.push(ans);
    int i=1;
    while(i<input.size()){
        TreeNode* inserter = inserterQueue.front();
        if(input[i]!=NULL){
            inserter->left = new TreeNode(input[i]);
            inserterQueue.push(inserter->left);
        }
        i++;
        if(input[i]!=NULL){
            inserter->right = new TreeNode(input[i]);
            inserterQueue.push(inserter->right);
        }
        i++;
        inserterQueue.pop();
    }
    return ans;
}

TreeNode* duplicateTree(TreeNode * original){
    TreeNode* newTree;
    if(original==nullptr)return nullptr;
    newTree = new TreeNode(original->val, duplicateTree(original->left), duplicateTree(original->right));
    return newTree;
}



vector<vector<TreeNode*>> globalTree;


vector<TreeNode*> generateTrees(int n);

vector<TreeNode*> generateTreesWithRootNodeM(int m, int n){
//    cout << " m -> " << m << " n -> " << n << endl;
    vector<TreeNode*>temp;
    if(m!=1 && globalTree[m-2].empty()){
        temp = generateTrees(m-1);
    }
    if(n!=m && globalTree[n-m-1].empty()){
        temp = generateTrees(n-m);
    }
    vector<TreeNode*> firstSet,secondSet;
    TreeNode* nullNode = nullptr;
    vector<TreeNode*> nullTreeVector = vector<TreeNode*>{nullNode};
    if(m==1) firstSet = nullTreeVector;
    else
    firstSet = globalTree[m-2];
    if(n==m)
        secondSet = nullTreeVector;
    else
    secondSet = globalTree[n-m-1];
    vector<TreeNode*> answer;
    for(int i=0;i<firstSet.size();i++){
        for(int j=0;j<secondSet.size();j++){
            TreeNode* right = duplicateTree(secondSet[j]);
            increaseEveryNode(right,m);
            TreeNode* head =new TreeNode(m,duplicateTree(firstSet[i]), right);
            answer.push_back(head);
        }
    }
    return answer;
}


vector<TreeNode*> generateTrees(int n) {
    globalTree.resize(8);
    TreeNode* baseTreeNode = new TreeNode(1);
    globalTree[0] = vector<TreeNode*>{baseTreeNode};
    vector<TreeNode*> temp;
    if(!globalTree[n-1].empty())return globalTree[n-1];
    else{
        for(int i=1;i<=n;i++){
//            cout << "root -> " << i << endl;
            temp = generateTreesWithRootNodeM(i, n);
//            for(int j=0;j<temp.size();j++){
//                printPreOrder(temp[j]);
//            }
//            cout << "    |    ";
            globalTree[n-1].insert(globalTree[n-1].end(),temp.begin(),temp.end());
            temp.clear();
        }
        return globalTree[n-1];
    }
}



int main(int argc, const char * argv[]) {

    vector<TreeNode*>temp;
    vector<int>preOrder;
    temp = generateTrees(3);
    for(int i=0;i<temp.size();i++){
        generatePreOrder(temp[i], preOrder);
        cout << "[";
        for(int j=0;j<preOrder.size();j++){
            cout << preOrder[j] <<" ";
        }
        cout << "], ";
        preOrder.clear();
    }
    cout << endl;
    
////    TreeNode input;
//    vector<int>v{0,1,2,NULL,4,5,6};
//    TreeNode* ans = generateTreeFromSimpleOrderWithNull(v);
//    cout << "root val -> " << ans->val << endl;
//    cout << "root left val -> " << ans->left->val << endl;
//    cout << "root right val -> " << ans->right->val << endl;
////    cout << "root left left val " << ans->left->left->val <<endl;
//    cout << "root left right val " << ans->left->right->val <<endl;
//    cout << "root right left val " << ans->right->left->val <<endl;
//    cout << "root right right val " << ans->right->right->val <<endl;
//
//
//
//
//    vector<int>preOrderOfAns;
//    increaseEveryNode(ans, 3);
//    TreeNode * duplicate = duplicateTree(ans);
//    generatePreOrder(duplicate, preOrderOfAns);
//    for(int i =0;i<preOrderOfAns.size();i++){
//        cout << preOrderOfAns[i]<< " ";
//    }
//    cout << endl;
//
    return 0;
}
