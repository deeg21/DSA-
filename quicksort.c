#include<stdio.h>

/*Quick sort sort:
1. Pivot Point. The pivot point is moved such that all values before the pivot point 
   are smaller to it and after the pivot point are greater to the value on pivot point.
   We can take a pivot point anywhere in the array: beginning, end or middle.
2. Partition Function.
3. Sub Arrays.
 
Given a array to be sorted.
 Its works on a pivot point. 
In addition we take 2 iterators, which move as a value greater or smaller than pivot point is found.
or the iterators reach the final point. At this point the ,  
 */
void QuickSort(int arr[],int start, int end)
{
  if(start<end)
  {
     int pIndex=partitionFunction(arr,start,end);
     quicksort(arr,start,pIndex-1);
     quicksort(arr,pIndex+1,end);
  }
}
/*

   1. choose the last element as the pivot.(pivot)
   2. Take a temporary pivot index as start.(pIndex)
   and iterator(itr) from start to end-1.
   3. if the current element is less than or equal to the pivot.(selected in step 1)
   4. Move the temporary pivot index forward.
   5. Swap the current element with the element at the temporary pivot idex.
   6. Move the pivot element to the correct pivot position (between the smaller and larger elements)
   7. pIndex++;
   8. swap a[i] and A[end]//pivot
   
*/
int partitionFunction(int arr[],int start,int end)
{
  int pIndex=start;
  int pivot=arr[end];
  int i;//iterator
/*compare each element with the pivot(i.e end element in this case) and swap a[i] and a[pindex] if its less that pIndex,  
   keep incrementing pIndex, as you swap*/
  for(int i=start;i<end;i++)
  {
    if(arr[i]<pivot)
    {
       swap(&arr[i],&arr[pIndex]);
       pIndex++;
    }
    //pIndex now has all elements smaller than it before it.
    swap(&arr[end],arr[pIndex]);//place the pivot at pIndex.
  }//for
  
  return pIndex;
  
}//partitionFunction

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

