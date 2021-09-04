#include<bits/stdc++.h>
using namespace std;
struct Node{
public:
	int data;
	Node* next;
};

bool sublistSearch()Node* first,Node* second)
{	
	Node*ptr1=first,*ptr2=second;
	if(first==NULL && second==NULL)
		return true;
	if(first==NULL ||( first!=NULL && second==NULL))
		return false;
	while(second!=NULL)
	{
		ptr2=second;
		while(ptr1!=NULL)
		{
			if(ptr2==NULL)
				return false;
			else if(ptr1->data==ptr2->data){
				ptr1=ptr1->next;
				ptr2=ptr2->next;
			}
			else
				break;
		}
		if(ptr1==NULL)
			return true;
		ptr1=first;
		second=second->next;
	}
	return false;

}