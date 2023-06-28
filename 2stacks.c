#include<stdio.h>

#define size 6
#define mid size/2
int stack[size];

int index1=0,index2=mid;

void push1(int val)
{
   if(index1>=mid)
   {
     printf("\n Stack1 is full!!\n");
     return;
   }
    
   stack[index1++]=val;
  
}

void push2(int val)
{
   if(index2>=size)
   {
     printf("\n Stack2 is full!!\n");
     return;
   }
   stack[index2++]=val;

}

int pop1()
{
   if(index1<0)
   {
       printf("\n Stack1 is empty!!\n");
       return -1;
   }
   return stack[index1--];

}

int pop2()
{
   if(index2<mid)
   {
       printf("\n Stack 2 is empty!!\n");
       return -1;
   }
   return stack[index2--];


}

int main()
{
   push1(10);
   push1(20);
   push1(30);
   
   push2(100);
   push2(200);
   push2(300);

   printf("\n stack1: %d",pop1());
   printf("\n stack1: %d",pop1());
   printf("\n stack1: %d",pop1());
   printf("\n stack1: %d",pop1());

   printf("\n stack2: %d",pop2());
   printf("\n stack2: %d",pop2());
   printf("\n stack2: %d",pop2());
   printf("\n stack2: %d",pop2());
   
   return 1;
}