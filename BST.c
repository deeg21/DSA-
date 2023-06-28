#include<stdio.h>
#include<stdlib.h>

/*Delete Node and Search functions need to be written for BST tree*/

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNewNode(int val)
{
    //Write your code here
    struct node* newNode=malloc(sizeof(struct node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->key=val;

   return newNode;
    
}
struct node* Insert(struct node* root, int val)
{
    if(root==NULL)
      root=getNewNode(val);
    else if(val<root->key)
      root->left=Insert(root->left,val);
    else if(val>root->key)
      root->right=Insert(root->right,val);
    return root;  
}


void Inorder(struct node* root)
{
  
   if(root==NULL){ return; }
    
    Inorder(root->left);
    printf("\t %d",root->key);
    Inorder(root->right); 
   //printf("\n");
}

/*
    This function is called by DeleteNode(). when both right and left node of
    the root/subroot node are not null. We need to replace the root/subroot with the right 
    minimum. This function is used to find the right minimum of the right node of root/subroot.

   the right key exists. It might or might not have left and right nodes. 
   if left node is NULL, then value of right node should be used.
*/

int getRightMin(struct node* root)
{
   
  
  struct node* temp=root;

   while(temp->left!=NULL)
     temp=temp->left;
   
   return temp->key;
   
}
int Search(struct node* root,int key)
{
    if(root==NULL)
     return 0;
    if(root->key==key)
        return 1;
    else if(root->key>key)
      return Search(root->left,key);
    else
     return Search(root->right,key);
}

/*
   1. Given a key, delete the node matching the key.
   2. if root node is null, exit.
   3.if root node is the key. There are 4 cases. 
     1. left and right children are null. simply delete the root.
     2. left child exists, right child is null. save the left child ,delete the  root, and make left child the new root.
     3. right child exists, but left child is null. save the right child, delete the root and make the right child new root.
     4. left and right child both exist for the root node to be deleted. Now find the (left) minimum of right child. 
        simply change the key value of the root node. No need to delete it. Now delete the left(minimum) of right child 
        as it has been replaced.
    
   3. search for key in left and right nodes.if key is less, go into left subtree. otherwise right.
   4. iterate left subtree or right subtree as chosen in step 3.
   5.
   


*/
struct node* DeleteNode(struct node* root, int key)
{
   if(root==NULL)
    return NULL;

   if(root->key<key)
     root->right=DeleteNode(root->right,key);
   else if(root->key>key)
     root->left=DeleteNode(root->left,key);
   else //if root value is equal to key
   {
      if(root->left==NULL && root->right==NULL)
      {
          //struct node* temp=root;
         // printf("\nleft and right nodes are null =%d",root->key);
          free(root);
          
          return NULL;
      }
      else if(root->left==NULL && root->right!=NULL)
      {
          //printf("\nleft node is null =%d",root->key);
          struct node* temp=root->right;
          free(root);
          return temp;
          
      }
      else if(root->right==NULL && root->left!=NULL)
      {
          //printf("\nright node is null =%d",root->key);
          struct node* temp=root->left;
          free(root);
          return temp;
          
      }
      else
      {
          int rightMin=getRightMin(root->right);
          root->key=rightMin;
          DeleteNode(root->right,rightMin);
          //return root;
       }

   }
   return root;
}

int main()
{
    struct node *root = NULL;
  
    //root=Insert(root,500);
    /*for(int i=1;i<10;++i)
    {
      if(i%2==0)
      root=Insert(root,i*i*i);// 8,64,216,512
      else
      root=Insert(root,i*i);//1,9,25,49,81
      //Inorder(root);
    } */

    root=Insert(root,100);
    root=Insert(root,90);
    root=Insert(root,110);
    root=Insert(root,80);
    root=Insert(root,60);
    root=Insert(root,105);
    root=Insert(root,120);
    root=Insert(root,112);
    Inorder(root);
    //root=DeleteNode(root,112);
    //Inorder(root);
       printf("\n");
    root=DeleteNode(root,100);
    Inorder(root);
    printf("\n");
    root=DeleteNode(root,120);
    Inorder(root);

    return 0;
}

