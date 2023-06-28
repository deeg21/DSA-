/*Create a Normal queue using Array
  In a normal queue using array we have a normal array of fixed size.
  The front and rear pointers point to beginning and last filled element 
  of array.
  initially front and rear pointers are empty.
  As elements are added rear pointer is incremented.
  As elements are removed front pointer is incremented until is reaches rear pointer or end of list.

    
  
*/

#include<stdio.h>

#define SIZE 100
int array[SIZE];

#define FALSE 0
#define TRUE 1

int rear=0;
int front=0;
int isQueueEmpty()
{
   if((front ==0 && rear==0) ||(front ==rear))
   {
      printf("\nQueue is empty!!\n");
      return TRUE;
     
    }
    
    
   return FALSE;
}
int isQueueFull()
{   //front==0 &&
  if(rear==SIZE)//1 to size
  {
      printf("\n Queue is Full!! \n");
      return TRUE;
   }
  return FALSE;
}

void enqueue(int val)
{
   
      if(isQueueFull()==TRUE)
       return ;
      array[rear++]=val;
    

}
void dequeue()
{
   //the queue is empty when front and rear are zero.
   //the queue is full when front=0 and rear=size;

   if(isQueueEmpty()==TRUE)
      return ;
  
   printf("\nDequeued Value: %d \n", array[front]);
     front++;
     // if(front!=rear)front++;
   //return val;
   
}
void printQueue()
{
   for(int i=front;i<rear;i++)
   {
     printf(" %d ",array[i]);
   }
}
int main()
{
   for(int i=0;i<SIZE;i++)
   {
      enqueue(i);
   }
   printQueue();
   for(int j=0;j<SIZE;j++)
   {
      dequeue(j);
   }
   printQueue();
}