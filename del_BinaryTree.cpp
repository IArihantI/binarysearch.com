#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node* left,*right;
};
Node* newNode(int key)
{
    Node* temp=new Node();
    temp->key=key;
    temp->left=temp->right=NULL;
    return temp;
};
void inorder(Node* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
void delDeepest(Node* root,Node* d_node)
{
    queue<Node*> q;
    q.push(root);
    Node* temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==d_node){
            temp=NULL;
            delete(d_node);
            return;
        }
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        }
        if(temp->right)
        {
            if(temp->right==d_node)
            {
                temp->right=NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->right);
        }
    }
}
Node* deletion(Node* root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->key==key)
            return NULL;
        else
            return root;
    }
    queue<Node*> q;
    q.push(root);
    Node* key_node=NULL;
    Node* temp;
    while(!q.empty())
    {   
        temp=q.front();
        q.pop();
        if(temp->key==key)
            key_node=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(key_node!=NULL)
    {
        int x=temp->key;
        delDeepest(root,temp);
        key_node->key=x;
    }
    return root;
}
int size(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return (size(root->left)+1+size(root->right));
}
int main() 
{ 
    struct Node* root = newNode(10); 
    root->left = newNode(11); 
    root->left->left = newNode(7); 
    root->left->right = newNode(12); 
    root->right = newNode(9); 
    root->right->left = newNode(15); 
    root->right->right = newNode(8); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 11; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
    cout<<endl;
    cout<<size(root)<<endl;
  
    return 0; 
} 