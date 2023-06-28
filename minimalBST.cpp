#include<iostream>
#include<vector>
using namespace std;


struct Node
{
   int data;
   Node* left;
   Node* right;

   Node(int Data)
   {
     data=Data;
     left=NULL;
     right=NULL;
   }
};
typedef struct Node Node;
Node* createMinimalBST(vector<int>array,int start,int end);
Node* createMinimalBST(vector<int> array);

Node* createMinimalBST(vector<int> array)
{
   std::cout<< array.size()<<"\n";
   return createMinimalBST(array,0,array.size()-1);
}
/*
    condsider a sorted vector array of length,10, 0-9 {1,2,3,4,5,6,7,8,9}
    midpint=4,create node for arr[4]i.e root
    now left start=0,end=3 mid=1 and right start=5 end=9 mid=7
    create a node at arr[1] and arr[7] for left and right
    start=0,end=0 mid=0/ start=2 end=3 mid=2     start=5 end=6 mid=5/ start=8, end=9, mid=8
    make a node at arr[0]/ make a node at arr[2] /make a node at arr[5]/make a node at arr[8]
    call left node for 0,-1, /start=1,end=0 /call left for start=2,end=1 and start=3,end=3 mid=3/  start=5,end=4 /start=6,end=6      start=8, end=7/ start=9,end=9
    create a node at array[3]           array[6]              array[9]
    call start=3, end=2....
*/
Node* createMinimalBST(vector<int>array,int start,int end)
{
   std::cout<<" "<<start<<" "<<end<<" ";

   if(start>end)
     return NULL;

  int mid=(start+end)/2;
  Node* newNode=new Node(array[mid]);
  
  newNode->left=createMinimalBST(array,start,mid-1);//0-3,5-6,
  newNode->right=createMinimalBST(array,mid+1,end);//5-9,7-9
  
  //std::cout<<newNode<<" ";
  return newNode;
   
}
void Inorder(struct Node* root)
{
   if(root==NULL){ return; }
    
    Inorder(root->left);
    printf("\t %d",root->data);
    Inorder(root->right); 
   
}


int main()
{
  vector<int> array{1,2,3,4,5,6,7,8,9,10};
  Node* root=createMinimalBST(array);
  cout<<"\n";
  Inorder(root);
  
}
