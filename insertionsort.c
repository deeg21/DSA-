#include<stdio.h>
/*****Tested December,2022*********/



/*
   
  Insertion Sort:1. Take each element of array starting from second element or index 1(n-1 iterations of for loop). Save it in "value".
  2. For each iteration of for loop go through steps 3 to 5.
  3. Compare this "value" with all elements previous to it.(while loop)
  4. if the previous value is greater (or lesser) move it one index higher.leaving its own place vacant.
  Keep comparing till first element is reached and moving higher up index, if its greater.
  5.Now insert this "value" in the last empty index which was moved.
  
  Time complexity: Best case: when the array is sorted. Then only the outer for loop is executed n times.
  Worst case: when we need ascending order, but the array is in descending order. Then for each element.
  at index i, there will be i-1 iterations of while loop.
  so 1,2,3,...n-1 iterations =n(n-1)/2 o(n2). 
  
*/

void InsertionSort(int a[],int size)
{
   int index=0,value=0;
   for(int i=1;i<size;i++)
   {
      value=a[i];//save the current element of array.  
      index=i;//iterator to all elements previous to current element.
      while(index>0 && a[index-1]>value)//compare the previous values with current element
      {
         a[index]=a[index-1];//move the greater element one index higher.
         index--;         
      } 
              
       a[index]=value;   
    }
}

void printArray(int arr[],int size)
{
   
   printf("\n Array: ");
   for(int i=0;i<size;i++)
   {
      printf(" %d\t",arr[i]);
   }
   printf("\n");
}

int main(void)
{
   int array[14]={1,2,10,0,40,99,72,3,33,8,2,30,-1,-5};
   InsertionSort(array,14);
   printArray(array,14);
}