/*
     Deepika Goyal:20 December,2022
     Revision: 7th July, 2023
     Status : Tested
*/
/*
* a Heap is a Complete Binary Tree. A complete binary tree is a binary tree in which all internal nodes are 
  filled except some leaf nodes and follow left to right and top to down order for filling the nodes.
  All CBT are balanced trees.
  
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
void IncreaseValue(std::vector<int> &heap, int index, int value);//7th June,2023
void DecreaseValue(std::vector<int> &heap, int index, int value);//7th June ,2023

/*A priority queue is a max heap, in which, the maximum value will be at the top. Here we are following the Post order traversal method.*/
/* Insert/Push value/key at the end of heap. In a binary tree, the value will be inserted in the last leaf node and 
   then heapified to move it to its correct position.*/
/* Alternative implementation for Push/Insert operation on heap.7th July, 2023 Techdose lecture video,  tested. Time complexity(o(logN)
    i=heap.size()-1;
    while(i>0 && heap[i/2]>heap[i])
    {
       swap(heap[i/2],heap[i]);
       i=i/2;
    }
*/
void Insert(std::vector<int> &heap,int val)
{
   int size=heap.size();
   heap.push_back(val);

  if(size>0)
     BuildHeap(heap,heap.size()-1);
}

void IncreaseValue(std::vector<int> &heap, int index, int value)
{
     heap[index]=value;
     int i=index;
     while(i>0 && heap[i]>heap[i/2])   //percolate up, same as insert key
     {
          swap(heap[i],heap[i/2]);
          i=i/2;
     }               
}

void DecreaseValue(std::vector<int> &heap, int index, int value)
{
     heap[index]=value;
     
     Heapify(heap,index,heap.size()-1);//This is MaxHeapify(), its a percolate down approach if viewed independently of BuildHeap.
     
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
    so we start heapify from the first internal node starting from bottom.)

 
   
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
   swap the first and last node. Now delete the last node. heapify the entire list by calling BuildHeap. */

void deleteHighestPriority(std::vector<int> &heap)
{
     int size=heap.size();
     if(size==0)
      std::cout<<"Priority Queue is Empty!!";//underflow
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

  /*7th June,2023, test Increase Key/Value, Decrease Key/value. This follows zero based indexing.*/
     IncreaseValue(heap,2,100);//insert value 100 at index 2,3rd position
     printHeap(heap);
     DecreaseValue(heap,1,1);//insert value 1 at index 1
     
      printHeap(heap);

}
