/*
     Deepika Goyal:20 December,2022
*/
/*
* a Heap is a Complete Binary Tree. A complete binary tree is a binary tree in which all internal nodes are 
  filled except some leaf nodes and follow left to right 
*/
#include<iostream>
#include<vector>

//using namespace std;

void BuildHeap(std::vector<int> &heap, int size);
void Heapify(std::vector<int> &heap, int index, int size);
void swap(int& x, int& y);
void insert(std::vector<int> &heap,int val);
//sint getHighestPriority(std::vector<int> &heap);
void printHeap(std::vector<int> &heap);
void deleteHighestPriority(std::vector<int> &heap);

/*A priority queue is a max heap, in which, the maximum value will be at the top. Here we are following the Post order traversal method.*/
/* Insert value at the end of heap. In a binary tree, the value will be inserted in the last leaf node and 
   then heapified to move it to its correct position.*/
void Insert(std::vector<int> &heap,int val)
{
   int size=heap.size();
   heap.push_back(val);

  if(size>0)
     BuildHeap(heap,heap.size()-1);
}

/*
   index: parent/root/top node of the binary tree.
   
*/

void Heapify(std::vector<int>& heap,int index,int size)
{

   int left=2*index+1;
   int right=left+1;

   int max=index;   //set max to index initially

   //Max Heap:check if left value is greater than root/subroot/parent value

   if(left<=size && heap[left]>heap[max])
    max=left;//point max to left node/child, if left is greater than root  

   if(right<=size && heap[right]>heap[max])//check if right node is greater than parent or left sibling whichever is greater
    max=right;//point max to right if max is greater
   
   if(max!=index)//max points to either left or right node now
   {
     swap(heap[max], heap[index]);//address of max (left or right whicver is greater, and parent/root node)
    
     /*now after swapping the left or right index which was max(was greater), contains the value of parent/top/index node,
     after swapping the max(left or right node) contains value of root/parent. so parent and child have been swapped.
     Now we need to heapify the swapped(right or left) with its children. it contains the lesser value than parent .
     This node needs to be more than its own children(if they exist).so heapify is required*/

     Heapify(heap,max,size);
   
   }
}
/* size/2 will be the leftest child node.
    

   This is the percolate up approach to Heapify. We start from lowest level. 

   The size of a PBT can be 1,3,7,13
   1.e 1,1+2=3,1+2+4=7,1+2+4+8=13,1+2+4+8+16=31, 
   
    In a CBT, all the internal nodes are intact, leaf nodes might not be complete.
    The internal nodes exist from 0 to N/2-1 in a 0 based index.
    Leaf nodes start from N/2 to N-1.
    so we start heapify from the first leaf node.???

 
   
*/

void BuildHeap(std::vector<int>& heap,int size)
{
   for(int i=size/2;i>=0;--i)
    Heapify(heap,i,size);
}

void swap(int& x,int& y)
{
   int temp=x;
   x=y;
   y=temp;
       
}
/* Deletes the highest priority Node which is the root/parent node or first node in the vector.
   swap the first and last node. Now delete the last node. heapify the entire list by calling BuildHeap  */
void deleteHighestPriority(std::vector<int> &heap)
{
     int size=heap.size();
     if(size==0)
      std::cout<<"Priority Queue is Empty!!";
     else
     {
         swap(heap[0],heap[size-1]);
         std::cout<<"Removing highest Priority!!"<<heap[size-1]<<"\n";
         heap.pop_back();//last element
         BuildHeap(heap,heap.size()-1);
     }
}
void printHeap(std::vector<int> &heap)
{
   if(heap.size()==0)
     std::cout<<"Priority queue is empty!!";
   else
   {
      std::cout<<"\n";
      for(auto i:heap)
        std::cout<<i<<" ";
      std::cout<<"\n";
   }
   
}

int main()
{
   std::vector<int> heap;
   for(int i=1;i<=4;++i)
     Insert(heap,i*10);
   Insert(heap,5);
   Insert(heap,35);
   Insert(heap,60);

   
   printHeap(heap);
   deleteHighestPriority(heap);
   printHeap(heap);

}