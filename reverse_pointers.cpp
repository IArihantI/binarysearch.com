#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* next;	
};
void reverse(Node **head_ref)
{
	struct Node* current=*(head_ref);
	struct Node* next;
	while(current->next!=NULL)
	{
		next=current->next;
		current->next=next->next;
		next->next=*(head_ref);
		*(head_ref)=next;
	}
}