/*Create a Circular queue using Array
  In a normal queue using array we have a normal array of fixed size.
  The front and rear pointers point to beginning and last filled element 
  of array.
  initially front and rear pointers are empty.
  As elements are added rear pointer is incremented.
  As elements are removed front pointer is incremented until is reaches rear pointer or end of list.
   
  DrawBack is that as elements are dequeued, the front of the array becomes empty and not utilised.
  so we are designing a circular queue
  rear=(rear+1)%size;//if rear==size, (size%)size=0, how??.Keep adding elements till the end
  front=(front+1)%size;
  
*/

#include<stdio.h>

#define SIZE 100
int array[SIZE];

#define FALSE 0
#define TRUE 1

int rear=-1;
int front=-1;

/*
  In a Circular Queue, the queue can be filled from the front if front of array has been popped/dequeued.
  So the front might be somewhere into the array and then the queue might be filled again from front. therefore
rear is less than front. Now if it is again popped, then front moves ahead and circles back to beginning of array.
  when all elements are dequeued from the array, front keeps incrementing, circling back from zero, then becoming equal
  to rear
*/
int isQueueEmpty()
{
//if front==size-1, rear=size-1
//if rear=i, front=i-1, then queue is not empty
   if((front ==-1 && rear==-1) ||(front ==rear))
   {
      printf("\nQueue is empty!!\n");
      return TRUE;
     
    }
 
    
   return FALSE;
}

int isQueueFull()
{   
  if((rear==SIZE-1 && front==0)|| (rear==front-1))//1 to size
  {
      printf("\n Queue is Full!! \n");
      return TRUE;
   }
  return FALSE;
}

void enqueue(int val)
{
      //if rear=size-1, rear=0 only if queue is empty at 0.
      if(isQueueFull()==TRUE)
       return ;
      
      rear=(rear+1)%SIZE;
      if(front==-1)front=0;//this helps to cheque if the queue is empty.
      
      array[rear]=val;
    

}
void dequeue()
{
   //the queue is empty when front and rear are zero.
   //the queue is full when front=0 and rear=size;

   if(isQueueEmpty()==TRUE)
      return ;
  
   printf("\nDequeued Value: %d \n", array[front]);
   front=(front+1)%SIZE;//IF front =size-1,front=0.
   
     
     
   
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
   /*for(int j=0;j<SIZE;j++)
   {
      dequeue(j);
   }
   printQueue();*/
}