#include<bits/stdc++.h>
using namespace std;
#include "binarytree.h"


void printdata(BinaryTreeNode<int> *root)
{

    if(root==NULL)
    return;

    cout<<root->data<<" : ";
    if(root->left!=NULL)
    {
        cout<<"L-"<<root->left->data<<" ";
    }
    if(root->right!=NULL)
    {
        cout<<"R-"<<root->right->data<<" ";
    }
    cout<<endl;
    printdata(root->left);
    printdata(root->right);

}


BinaryTreeNode<int> * TakeInput ()
{
    int rootdata;
    cout<<"Enter data: "<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int> *leftChild=TakeInput();
    BinaryTreeNode<int> *rightChild=TakeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

BinaryTreeNode<int> * takeinputlevelwise()
{
    int rootdata;
    cout<<"Enter root data: "<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root); 
    while(pendingNode.size()!=0)
    {
        BinaryTreeNode<int> * front=pendingNode.front();
        pendingNode.pop();
        cout<<"Enter left Node data of "<<front->data<<":"<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild!=-1)
        {
            BinaryTreeNode<int>* l_child=new BinaryTreeNode<int>(leftChild);
            front->left=l_child;
            pendingNode.push(l_child);
        } 
        cout<<"Enter Right Node data of "<<front->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild!=-1)
        {
            BinaryTreeNode<int>* r_child=new BinaryTreeNode<int>(rightChild);
            front->right=r_child;
            pendingNode.push(r_child);
        } 
    }
        return root;
}

//traversals in binary tree
// _1. pre order traversal N->left->right
// _2. post-order traversal left->right->node;
// _3. in-order traversal left->node->right
// inorder traversal
void inorder(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


//postorder traversal
void postorder(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//preorder traversal
void preorder(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// copy-1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1
void PrintbinarytreeLevelwise(BinaryTreeNode<int> * root)
{
    queue<BinaryTreeNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode<int> * front=pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL)
        {
            cout<<"L-"<<front->left->data<<" ";
            pendingnodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<"R-"<<front->right->data;
            pendingnodes.push(front->right);
        }
        cout<<endl;
    }
}

int numofnode(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    return 0;
    int ans=1;
    ans+=numofnode(root->left);
    ans+=numofnode(root->right);
    return ans;
}

int main()
{

// BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
// BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
// BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3);
// root->left=node1;
// root->right=node2;

// BinaryTreeNode<int> * root=TakeInput();
BinaryTreeNode<int> * root=takeinputlevelwise();
PrintbinarytreeLevelwise(root);
cout<<"Number of nodes in a binary tree is: "<<numofnode(root)<<endl;
cout<<"INorder Traversal of Binary Tree:->"<<endl;
inorder(root);
cout<<endl;
cout<<"Postorder Traversal of Binary Tree:->"<<endl;
postorder(root);
cout<<endl;
cout<<"Pre Order Traversal of Binary Tree:->"<<endl;
preorder(root);
cout<<endl;
// printdata(root);
    return 0;
}