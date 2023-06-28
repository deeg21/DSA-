#include<stdio.h>


void MergeSort(int [],int,int );
void print(int[],int );
void Merge(int[],int, int,int);


void MergeSort(int arr[],int start,int end)
{
   if(start<end)
   {
      int mid=(start+end)/2;
      MergeSort(arr,start,mid);
      MergeSort(arr,mid+1,end);
      Merge(arr,start,mid,end);
      
      
   }
}
void Merge(int a[],int start, int mid,int end)
{
    int temp[end-start+1];
    int i=start,j=mid+1,k=0;//if start=0, end=2,mid=1,i=0to1,j=2;

    for(;i<=mid && j<=end;)//if any of i and j reaches its limit, exit the loop, both 
     {
        if(a[i]<a[j]){temp[k++]=a[i++];}
        else{temp[k++]=a[j++];}//if a[j]>a[i]
           
     }//for
     while(i<=mid){temp[k++]=a[i++];}
     while(j<=end){temp[k++]=a[j++];}

      k=0;
     for(int l=start;l<=end;++l,++k){a[l]=temp[k];}//

}
void print(int arr[],int size)
{
   printf("\n Array!!: ");
   for(int i=0;i<size;i++)
     printf("%d\t",arr[i]);
  printf("\n");    
}
int main()
{
    int arr[11]={9,2,8,4,6,3,5,10,1,7,-1};
    print(arr,11);
    MergeSort(arr,0,10);
    print(arr,11);

}