#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

struct Node *newNode(int data)
{
    Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void segregate(Node** head_ref)
{
  Node* end=*(head_ref);
  Node* prev=NULL;
  Node* curr=*(head_ref);
  while(end->next!=NULL)
    end=end->next;
  Node* new_end=end;
  while(curr->data %2 !=0 && curr!=end)
  {
    new_end->next=curr;
    curr=curr->next;
    new_end->next->next=NULL;
    new_end=new_end->next;
  }
  if(curr->data%2==0)
    {
      *(head_ref)=curr;
      while(curr!=end)
      {
        if((curr->data)%2==0)
          {
            prev=curr;
            curr=curr->next;
          }
          else
          {
            prev->next=curr->next;
            curr->next=NULL;
            new_end->next=curr;
            new_end=curr;
            curr=prev->end;
          }
      }
    }
    else
      if(new_end!=end && (end->data%2!=0))
      {
        prev->next=end->next;
        end->next=NULL;
        new_end->next=NULL;
      }
      return;
}

void push(Node ** head_ref,int data);
int countNode(Node*head,int n);
void getIntersectionNode(Node* a, Node*b)
{
  int c1=countNode(a,0);
  int c2=countNode(b,0);
  int d;
  if(c1>c2){
    d=c1-c2;
    for(int i=0;i<d;i++)
          a=a->next;
  }
  else{
    d=c2-c1;
    for(int i=0;i<d;i++)
      b=b->next;
  }
  while(a!=NULL && b!=NULL)
  {
    if(a==b)
      cout<<a->data;
    a=a->next;
    b=b->next;
  }
}

Node* sortedIntersect(Node* a, Node* b)
{
    Node* result=NULL;
    Node** lastrefptr=&result;
    while(a!=NULL && b!=NULL)
    {
        if(a->data==b->data)
        {
            push(lastrefptr,a->data);
            lastrefptr=&((*(lastrefptr)) ->next);
            a=a->next;
            b=b->next;
        }
        else if(a->data > b->data)
            b=b->next;
        else
            a=a->next;
    }
}

void swapNodes(Node** head,int x,int y)
{
    
    if(x==y) return;
    Node *prev_x=NULL;
    Node *xa=*head;
    while(xa!=NULL && xa->data!=x)
    {
        prev_x=xa;
        xa=xa->next;
    }
    Node *prev_y=NULL;
    Node *yb=*head;
    while(yb!=NULL && yb->data!=y)
    {
        prev_y=yb;
        yb=yb->next;
    }
    if(yb==NULL || xa==NULL)
        return;
    if(prev_x!=NULL)
        prev_x->next=yb;
    else
        *head=yb;
    if(prev_y!=NULL)
        prev_y->next=xa;
    else
        *head=xa;
    Node *c=xa->next;
    xa->next=yb->next;
    yb->next=c;
    
}

void delDuplicate_unsorted_hash(Node* head)
{
    unordered_set <int> seen;
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL)
    {
        if(seen.find(curr->data)!=seen.end())
        {
            prev->next=curr->next;
            delete(curr);
        }
        else{
            seen.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }
}

void delDuplicate_unsorted(Node* head)
{
    Node *first,*second,*prev;
    first=head;
    
    while(first!=NULL && first->next!=NULL)
    {   
        second=first;
        
        while(second->next!=NULL)
        {
            if(first->data==second->next->data)
            {
                prev=second->next;
                second->next=second->next->next;
                delete(prev);
            }
            else{
                second=second->next;
            }
        }
        first=first->next;
    }
}

void delDuplicate(Node* head)
{
    Node* current=head;
    
    while(current->next!=NULL)
    {   
        Node* nex=new Node();
        if(current->data==current->next->data)
        {
            nex=current->next;
            current->next=nex->next;
            delete nex;
        }
        else{
        current=current->next;}
    }
}

void printList(Node* n)
{
  while(n!=NULL)
  {
    cout<<n->data<<" ";
    n=n->next;
  }
  cout<<endl;
}

int GetNth(Node* head,int n)
{
  Node* current=head;
  while(n>0 && current->next!=NULL)
  {
    current=current->next;
    n--;
  }
  if(n!=0)
    return -1;
  return current->data;
}

int countL_Node(Node*t)
{
    int l=1;
    Node*ptr=t;
    while(t->next!=ptr)
    {
        l++;
        t=t->next;
    }
    return l;
}

int countNodesinLoop(Node*head)
{
    Node*s=head;
    Node*f=head;
    while(s && f && f->next)
    {
        s=s->next;
        f=f->next->next;
        
        if(s==f)
            return countL_Node(s);
    }
    return 0;
}

int list_length(Node* head)
{
  int count=0;
  Node* current=head;
  while(current!=NULL)
  {
    current=current->next;
    count++;
  }
  return count;
}

int middleNode(Node* head)
{
    Node* temp=new Node();
    Node* f=head;
    Node* s=head;
    while(f!=NULL)
    {
        s=s->next;
        temp=f->next;
        f=temp->next;
    }
    return s->data;
}
int GetNthfromend(Node* head,int n)
{   
    Node* current=head;
    int a=list_length(current)-n;
    //return a;
    return GetNth(head,a);
}

void GetNthfromend_pointers(Node* head,int n)
{
    int count=0;
    Node* f=head;
    Node* s=head;
    while(n!=count)
    {
        f=f->next;
        count++;
    }
    while(f!=NULL)
    {
        s=s->next;
        f=f->next;
    }
    cout<<s->data<<endl;
}

void delteNode(Node** head_ref,int del_data)
{
  Node* prev=new Node();
  Node* temp=*(head_ref);
  if(*(head_ref)==NULL)
  {
    cout<<"Empty List"<<endl;
    return;
  }
  if(temp!=NULL && temp->data==del_data)
  {
    *(head_ref)=temp->next;
    delete temp;
    return;
  }
  
  while(temp!=NULL && temp->data != del_data)
  {
      prev=temp;
      temp=temp->next;
  }
  if(temp->next==NULL)
    return;
  prev->next=temp->next;
  delete temp;
}

void deleteList(Node **head_ref)
{
  Node* current=*(head_ref);
  Node*next=new Node();
  while(current!=NULL)
  {
    next=current->next;
    delete current;
    current=next;
  }
  *(head_ref)=NULL;
}

bool search(Node* head,int key)
{
    Node* current=head;
    while(current!=NULL)
    {
        if(current->data==key)
            return true;
        current=current->next;
    }
    return false;
}

bool search_rec(Node* head,int key)
{
    if(head==NULL)
        return false;
    if(head->data==key)
        return true;
    return search_rec(head->next,key);
}

Node* reverseList(Node* head)
{
    Node*temp=NULL;
    Node*a=head;
    Node*b=a->next;
    while(b!=NULL)
    {
        a->next=temp;
        temp=a;
        a=b;
        if(a!=NULL)
            b=a->next;
    }
    a->next=temp;
    temp=a;
    return temp;
}

bool isPalindrome(Node* head)
{
    Node*s=head;
    Node*f=head;
    Node* prev_s=new Node();
    while(f!=NULL &&f->next!=NULL)
    {   
        prev_s=s;
        s=s->next;
        f=f->next->next;
    }
    if(f==NULL)
    {
        Node*h=s;
        Node*rev=reverseList(s);
        while(rev!=NULL)
        {
            if(rev->data!=head->data)
            {
                return false;
            }
            head=head->next;
            rev=rev->next;
        }
    return true;
    }
    else
    {
        Node*rev=reverseList(s->next);
        while(rev!=NULL && head!=s->next)
        {
            if(rev->data!=head->data)
            {
                return false;
            }
            head=head->next;
            rev=rev->next;
        }
        
        return true;
    }
}

int list_length_rec(Node* head,int count)
{
  if(head==NULL)
    return count;
  count++;
  return list_length_rec(head->next,count);
}

int countNode(Node* head,int n)
{
    static int count=0;
    if(head==NULL)
        return count;
    if(head->data==n)
    {
        ++count;
    }
    return countNode(head->next,n);
}

void delete_at_Pos(Node** head_ref,int position)
{
  if(position<0)
  {
    cout<<"Enter a valid position"<<endl;
    return;
  }
  Node* temp=*(head_ref);
  Node*prev=new Node();
  if(position==0)
  {
    *(head_ref)=temp->next;
    delete temp;
    return;
  }
  while(position>0 &&temp!=NULL)
  { 
    prev=temp;
    temp=temp->next;
    position--;
  }
  if(temp==NULL || temp->next==NULL)
    return;
  prev->next=temp->next;
  delete temp;
}

bool detectLoop(Node* h)
{
    unordered_set<Node*> s;
    while(h!=NULL)
    {
        if(s.find(h)!=s.end())
            return true;
        s.insert(h);
        h=h->next;
    }
    return false;
}

void push(Node** head_ref,int new_data)
{
    Node *new_node=new Node();
    new_node->data=new_data;
    new_node->next=*(head_ref);
    *(head_ref)=new_node;
}

void insertAfter(Node* prev_node,int new_data)
{
    if(prev_node==NULL)
    {
        cout<<"Previous Node is Null use the Push Function"<<endl;
        return;
    }
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

void appendLast(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    Node* last=*head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    last->next=new_node;
    return;
}

int main()
{
  Node *head=NULL;
  Node *second=NULL;
  Node *third=NULL;
  Node *fourth=NULL;
  Node *fifth=NULL;
  Node *sixth=NULL;

  head = new Node();
  second = new Node();
  third = new Node();
  fourth = new Node();
  fifth = new Node();
  sixth = new Node();
  
  head->data=1;
  head->next=second;

  second->data=2;
  second->next=third;

  third->data=3;
  third->next=fourth;
  
  fourth->data=4;
  fourth->next=fifth;
  
  fifth->data=5;
  fifth->next=sixth;
  
  sixth->data=6;
  sixth->next=NULL;

  printList(head);
  
  /*push(&head,0);
  printList(head);
  
  insertAfter(second,2);
  printList(head);
  
  appendLast(&head,4);
  printList(head);
  
  
  cout<<list_length_rec(head,0)<<endl;
  cout<<search_rec(head,-1)<<endl;
  cout<<GetNth(head,0)<<endl;*/
  //cout<<GetNthfromend(head,2)<<endl;
  //cout<<list_length(head)<<endl;
  //GetNthfromend_pointers(head,2);
  //cout<<middleNode(head)<<endl;
  //cout<<countNode(head,8)<<endl;
  //cout<<detectLoop(head)<<endl;
  //printList(reverseList(head));
  //cout<<isPalindrome(head)<<endl;
  //delDuplicate(head);
  //delDuplicate_unsorted(head);
  //swapNodes(&head,1,6);
  //printList(head);
  printList(sortedIntersect(head,head));
  return 0;
}
