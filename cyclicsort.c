#include<stdio.h>

int SortArray(int[], int);
void swap(int* ,int*);
void printArray(int[],int);

int main()
{
    //int arr[6]={1,2,6,4,3,5};//tested
    int arr[6]={1,2,3,4,3,2};
    int result=SortArray(arr,6);
    
    printf("\n ****Duplicates: %s *********\n",result==0?"false":"true");
    
    int arr2[5]={1,4,4,3,2};
    result=SortArray(arr2,5);

    printf("\n ****Duplicates: %s *********\n",result==0?"false":"true");

}


int SortArray(int arr[], int size)
{
    ///sortArray(arr,size);
    for(int i=0;i<size;i++)
    {
        while(arr[i]!=i+1)
        {          
            if(arr[arr[i]-1]==arr[i])//if the elements at two indexes are equal
              return 1;
              
             //the element a[i] belongs to index a[i]-1
             swap(&arr[i],&arr[arr[i]-1]);
            
        }
        
    }//for
    //printArray(arr,size);
    return 0;
    
}


void swap(int* x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}


void printArray(int arr[],int size)
{
   for(int i=0;i<size;i++)
   {
      printf("arr[%d]:%d ",i, arr[i]);
   }

}