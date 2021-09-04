#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* link;
};
struct Queue{
    struct Node *front, *rear;
};
void enQueue(Queue* q,int new_data)
{
    struct Node* temp=new Node;
    temp->data=new_data;
    if(q->front==NULL)
        q->front=temp;
    else
        q->rear->link=temp;
    
    q->rear=temp;
    q->rear->link=q->front;
}
int deQueue(Queue* q)
{
    if(q->front==NULL)
        return -1;
    else
    {
        if(q->front==q->rear)
        {
            int s=q->front->data;
            free(q->front);
            q->front=NULL;
            q->rear=NULL;
            return s;
        }
        else
        {
            struct Node* temp=q->front;
            int s=temp->data;
            q->front=q->front->link;
            q->rear->link=q->front;
            free(temp);
            return s;
        }
    }
}
void displayQueue(struct Queue* q) 
{ 
    struct Node* temp = q->front; 
    printf("\nElements in Circular Queue are: "); 
    while (temp->link != q->front) { 
        printf("%d ", temp->data); 
        temp = temp->link; 
    } 
    printf("%d", temp->data); 
} 
  
/* Driver of the program */
int main() 
{ 
    // Create a queue and initialize front and rear 
    Queue* q = new Queue; 
    q->front = q->rear = NULL; 
  
    // Inserting elements in Circular Queue 
    enQueue(q, 14); 
    enQueue(q, 22); 
    enQueue(q, 6); 
  
    // Display elements present in Circular Queue 
    displayQueue(q); 
  
    // Deleting elements from Circular Queue 
    printf("\nDeleted value = %d", deQueue(q)); 
    printf("\nDeleted value = %d", deQueue(q)); 
  
    // Remaining elements in Circular Queue 
    displayQueue(q); 
  
    enQueue(q, 9); 
    enQueue(q, 20); 
    displayQueue(q); 
  
    return 0; 
}