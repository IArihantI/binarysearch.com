#include<bits/stdc++.h>
using namespace std;
struct DqueNode{
    int value;
    DqueNode* next;
    DqueNode* prev;
};
class deque{
    private:
    DqueNode* head;
    DqueNode* tail;
    public:
    deque()
    {
        head=tail=NULL;
    }
    bool isEmpty()
    {
        if(head==NULL)
            return true;
        return false;
    }
    int size()
    {
        if(!isEmpty()){
            DqueNode* temp=head;
            int len=0;
            while(temp!=NULL)
            {
                len++;
                temp=temp->next;
            }
            return len;
        }
        return 0;
    }
}