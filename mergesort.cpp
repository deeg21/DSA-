#include<iostream>
#include<array>
#include<list>
#include<vector>
#include<iterator>

template<typename Container>
void print(const Container &container)
{
    for(const auto &v:container)
     std::cout<<v<<"\n";
}

template<typename Container>
void MergeSort(const Container &container,int start,int end)
{
   int mid=(start+end)/2;
   MergeSort(Container,start,mid);
   MergeSort(Container,mid+1,end);

   int j=0;
   //auto it_begin=container.begin();
   std::advance(start);
   for(int i=start;i<=mid;i++)
   {
      if(container>
   }
   
}
/*
   Given start, mid and end of the array. 
   You have 2 arrays(container type allowed) starting from start to mid
   and mid+1 to end.
   Even though we can find the begining of container using begin() and end().
   But here the relative start and end is changing. So required as argument.
   The iterator functionality required is 
   1. Accessing simultaneously the start and middle of an array.
      (so we need an iterator to front and middle of an array).
   2. Copying the values to another temporary array using member access operator.
   3. Again copying the values of temporary array back to the array(container).
   
    So we need member access at 2 locations simultaneously, forward iteration, writting.
    This functionality can be easily satisified with a forward iterator.
    
    A vector, deque and array satisfy this functionality. The [] and 'at' operators are available 
    only for these three containers. So if you use a list container for merge sort, the program will crash.
          

*/
template<typename Container>
void Merge(const Container *container, int start, int mid, int end)
{
    auto itr=begin(container);//returns an iterator past the beginning of container
    auto start_itr=itr+start;
    auto mid_itr=itr+mid+1;//one past the middle of array for the second part of array
    auto end_itr=end(container);//returns an iterator past the end of container.
    
    while(start_itr<=(itr+mid) && mid_itr<=(end_itr-1))
    {
       
    }
    
}

int main()
{
    std::array<int,10> a1;
    a1={10,45,38,8,3,67,99,7,0,102};
    print(a1);
    MergeSort(a1,0,a1.size()-1);
    print(a1);
    
}
