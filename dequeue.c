#include<stdio.h>
#include<stdlib.h> //malloc

/*
    A deque is a double ended queue. 
    A stack (LIFO) and Queue (FIFO) are special cases of a deque.
    
   
*/

#define TRUE 1
#define FALSE 0
struct node
{
   int data;
   struct node* next;
   struct node* prev;
};

typedef struct node *Node;//typedef a pointer to node as Node
Node front=NULL, rear=NULL;

Node getNewNode(int val)
{
   Node newNode=malloc(sizeof(struct node));
   newNode->data=val;
   newNode->next=NULL;
   newNode->prev=NULL;
   return newNode;//address contained in newNode
}


/*Front pointer is used while inserting from front.
* Initially both pointers are NULL.
* So rear would point to the first node that was inserted. 
* Every first node inserted is pushed backwards as new nodes are inserted from front.
* 
*/
void InsertFront(int val)
{
   Node newNode=getNewNode(val);
   
   if(front==NULL)
   {
      front=newNode;
      rear=newNode;//rear will point to the same node, unless nodes are inserted from last by insertLast()

   }
   else
   {
     newNode->next=front;//save current node, pointed by front.
     front->prev=newNode;//backwards linking of front node to newnode.
     front=newNode;
   }


}
/*
* rear pointer is used when adding nodes from the last.
*
*
*/
void InsertLast(int val)
{
   Node newNode=getNewNode(val);
   if(rear==NULL)
   {
     rear=front=newNode;
   }
   else
   {
     rear->next=newNode;//let current rear/last node point to newNode as last node
     newNode->prev=rear;//let the new node point to the previous rear node
     rear=newNode;
   }
   
}
void printDequeFirst()
{
   Node temp=front;
   if(front==NULL)
     {printf("\n Deque is Empty!!\n");return;}

   printf("\n Printing Deque...   ");
   while(temp)
   {
      printf("\t %p :%d ",temp,temp->data);
      temp=temp->next;
   }
   
   printf("\n");
   
}
void printDequeLast()
{
   Node temp=rear;
   if(rear==NULL)
     {printf("\n Deque is Empty!!\n");return;}

   printf("\n Printing Deque...   ");
   while(temp)
   {
      printf("\t %p :%d ",temp,temp->data);
      temp=temp->prev;
   }
   printf("\n");
}

void deleteFront()
{
   if(front==NULL)       //Case 1. No element
     {printf("\n Deque is Empty !!\n");return;} 
   else if(front->next==NULL)//case 2: 1 element in deque
   {
     free(front);
     
     front=rear=NULL;//rear also needs to be set to NULL, otherwise it will become a dangling pointer.
   }
   else   //case 3: More than 1 element in deque
   {
     
     Node temp=front;
     front=front->next;
     front->prev=NULL;
     free(temp);
   }
}

void deleteLast()
{
   if(rear==NULL)       //Case 1. No element
     {printf("\n Deque is Empty !!\n");return;} 
   else if(rear->prev==NULL)//case 2: 1 element in deque
   {
     free(rear);
     front=rear=NULL;//rear also needs to be set to NULL, otherwise it will become a dangling pointer.
   }
   else   //case 3: More than 1 element in deque
   {
     
     Node temp=rear;
     rear=rear->prev;
     rear->next=NULL;
     free(temp);
   }
}

int isEmpty()
{
   if(front==NULL)
     return TRUE;
   return FALSE;
}

int getFront()
{
   if(isEmpty==TRUE)return -1;
    return front->data;
}
int getRear()
{
   if(isEmpty==TRUE)return -1;
    return rear->data;
}
int main()
{
   for(int i=0;i<10;i++)
   {

      InsertFront(i*10);
   }
   printDequeFirst();
   printDequeLast();
   for(int j=0;j<10;j++)
     deleteFront();
   printDequeFirst();
   printDequeLast();
   for(int i=11;i<20;i++)
   {
      InsertLast(i*10);
   }
   printDequeFirst();
   printDequeLast();

   for(int j=0;j<10;j++)
     deleteLast();

   printDequeFirst();
   printDequeLast();
}