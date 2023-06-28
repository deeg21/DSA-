#include<stdio.h>

void printArray(int arr[],int n)
{
   printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
  printf("\n");
}

void ReverseArray(int arr[],int n)
{
   int temp=0;
   for(int i=0;i<n/2;i++)//arr={1,2,3,4,5,6} n/2=3 i=0-->5,1-->4,2-->3,
   {
       temp=arr[i];
       arr[i]=arr[n-i-1];
       arr[n-i-1]=temp;
   }
   printArray(arr,n);
}


void RotateArray(int arr[],int n, int k)
{
   ReverseArray(arr,n-k);//arr,3
    
    
    //now reverse the last k elements
    ReverseArray(&arr[n-k],k);
    printArray(arr,n);
    //now Reverse the whole array
    ReverseArray(arr,n);
}
int main()
{
   
   int a[6]={1,2,3,4,5,6};

    RotateArray(a,6,3);
   
}

