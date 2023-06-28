#include<stdio.h>
#include<stdlib.h>

//Definition for a linked list node.

struct node
{
    int data;
    struct node *next;
};
struct node* head=NULL;
void addLast(int data)
{
    struct node *newNode=malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=data;
   if (head==NULL)
   {
      head=newNode;
      return;
   }

   struct node* temp=head;
   while(temp->next!=NULL)
   {
      temp=temp->next;
   }
   temp->next=newNode;

}

/*delete a node based on value*/
void deleteNode(int key)
{
   if(head==NULL)
     return;
 
  struct node* temp=head;

  if(head->data==key)
  {
     //temp=head;
     head=head->next;
     free(temp); 
     return;      
  }

  while(temp->next!=NULL)
  {
     if(temp->next->data==key)
     {
          struct node* delNode=temp->next;
          temp->next=temp->next->next;
          free(delNode);
          break;
                   
     }
     temp=temp->next;
  }
   
}

int getMiddleNode()
{
     int len=0;

    //write your code
    if(head==NULL)
       return -1;

    len=1;
 
   


    printf("\n%d %d\n",len,len/2);

    temp=head;

   int mid=(len%2==0)?len/2:(len+1)/2;
    for(int i=1;i<mid;++i)
    {
        temp=temp->next;   
    }
    
    return temp->data;   
}

void printList()
{
    struct node *temp = head;

    printf("\n");

    while(temp != NULL)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
    printf("\n");
}
int main()
{

    int key;
    //scanf("%d",&key);

    while(key!=-1)
    {  
       printf("\n Please Enter a Key!!For exiting, type -1\n");
       scanf("%d",&key);
       addLast(key);
   }

    /*addLast(10);
    addLast(20);
    addLast(30);
    addLast(30);*/

    printList();   

    //int key;
    printf("\n Please Enter a Key for deletion!!For exiting, type -1\n");
    scanf("%d",&key);

    deleteNode( key);

    printList();
    
    printf("Middle Node: %d\n",getMiddleNode());     
}