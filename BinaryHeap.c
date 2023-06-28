#include<iostream>

/*
   Given a array, construct a max heap. i.e the topmost node will have the maximum value.
   If we construct a heap with a vector, each time a node is added at the last i.e leaf node
   then it is heapified. i.e if the value of node is greater, it pushed upwards.
   
*/

#define TRUE 1
#define FALSE 0
#define SIZE 6

/*struct node
{
   int data;
   struct node* next;
   struct node* previous;
};
 struct node *root=NULL;*/

  
/* */
void BuildHeap()
{
   for(int i=0;i<=SIZE/2;i++)
   {
      Heapify(arr,i,SIZE);
   }
}

void Heapify(int arr, int index,int size)
{
   
   
}

int main()
{
   int array[SIZE];
   for(int i=1;i<=SIZE;++i)
      array[i]=i*SIZE;
  
   
   
}