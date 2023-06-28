#include<stdio.h>
#include<stdlib.h>//malloc

struct node
{
   struct node* next;
   int data;
};
typedef struct node Node;

struct node* front=NULL,*rear=NULL;

/* A queue is a FIFO data structure.
  Implement a queue using a linked list
  Elements are added in end of linked list.
  Removal of elements is from front.
  We have 2 pointers, to the front and end of list.
  Initially both pointers point to null.
  If front and end pointers are empty, then list is empty.
  As we add nodes to the list, rear pointer is incremented. (size is not tracked).
  As we remove nodes from the list, the front pointer is incremented until front points to NULL.
  Then rear is also set to NULL.
  There is no restriction on size
*/
void enqueue(int value)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL && rear==NULL)
    {
      front=newNode;
      rear=newNode;
      //return ;
    }
    else
    {
      //rear is pointing to the last node
      rear->next=newNode;
      rear=newNode;
    }
}
/*retrieve the first element from the queue pointed to by front pointer.FIFO
   if front and rear are both NULL, then the list is empty.
   if front reaches end of list i.e null, set rear also to NULL.
   Return Value: value retrieved, -1 if list is empty.
*/
int dequeue()
{
    if(front==NULL && rear==NULL)
     return -1;
    struct node* temp=front;
    front=front->next;
    if(front==NULL)
     rear=NULL;
     int val=temp->data;
     free(temp);
    return val;

}
void printQueue()
{
   if(front==NULL)
   {
      printf("\n Queue is empty!!\n");
      return;
   }
   struct node* temp=front;
   while(temp!=NULL)
   {
      printf("\t%p: %d ",temp,temp->data);
      temp=temp->next;
    }
    printf("\n");
}
int main()
{
    for(int i=1;i<=10;i++)
    {
       enqueue(10*i);  
    }
    printQueue();
    printf("\nEmptying the queue!!..");
    for(int i=5;i>0;--i)
      printf(" %d ",dequeue());
     printQueue();

    for(int i=11;i<=20;i++)
    {
       enqueue(10*i);  
    }
    printQueue();
    printf("\nEmptying the queue!!..");
    for(int i=15;i>0;--i)
      printf(" %d ",dequeue());
     printQueue();
    
}