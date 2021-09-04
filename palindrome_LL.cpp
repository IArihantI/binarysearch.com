#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	char data;
	Node* next;
};

Node* newNode(char key)
{
    Node*temp=new Node;
    temp->data=key;
    temp->next=NULL;
    return temp;
}

bool pali(Node*head)
{
	stack<char> s;
	Node*h=head;
	while(h!=NULL)
	{
		s.push(h->data);
		h=h->next;
	}
	int count=s.size()/2;
	while(head!=NULL && !(s.empty()) && (count!=0))
	{   
	    char c=s.top();
	    s.pop();
		if(c!=head->data)
		{
			return false;
		}
		head=head->next;
		count--;
	}
	return true;
}

int main()
{
	Node* head= newNode('R');
	head->next=newNode('A');
	head->next->next=newNode('D');
	head->next->next->next=newNode('A');
	head->next->next->next->next=newNode('R');
	cout<<pali(head)<<endl;
	return 0;
}