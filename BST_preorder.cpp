#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left,*right;
    Node(int data):data(data),left(NULL),right(NULL){}
};
Node* buildBST(vector<int>& pre)
{
    if(pre.empty())
    return NULL;
    int rootVal=pre[0];
    vector<int> smaller,greater;
    for(int i=1;i<(int)pre.size();i++)
    {
        if(pre[i]>rootVal)
        greater.push_back(pre[i]);
        else
        smaller.push_back(pre[i]);
    }
    Node* root1=new Node(rootVal);
    root1->left=buildBST(smaller);
    root1->right=buildBST(greater);
    return root1;
}
void inorder(Node* root)
{
if (root == NULL)
return;

inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}

int main()
{
vector<int> pre;
pre.push_back(10);
pre.push_back(5);
pre.push_back(1);
pre.push_back(7);
pre.push_back(40);
pre.push_back(50);
Node* root = buildBST(pre);

inorder(root);

return 0;

}