#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node* next;
};
//struct node* head=NULL;

int CalculateLoopLength(struct node* slow)
{
    int len=0;
    
    if(slow==NULL)
     return 0;
     
    struct node* temp=slow;
    
    do
    {
      temp=temp->next;
      ++len;
    }while(temp!=slow);
    
    return len;
}

int hasLoop(struct node **head)
{
   struct node* fast=*head,*slow=*head;  
   
   while((slow!=NULL) && (fast!=NULL) && (fast->next!=NULL))
   {
       fast=fast->next->next;
       slow=slow->next;
       //printf("\n %x \n",slow->next);
       if(fast==slow)
       {
          //return 1;
          printf("\n slow=%x:%d fast=%x: %d\n",slow,slow->data,fast,fast->data);
          return CalculateLoopLength(slow);
       }
   }
   return 0;
}

void addNode(struct node**head,int val)
{
   struct node* newNode=malloc(sizeof(struct node));
   newNode->next=NULL;
   newNode->data=val;
   
   if(*head==NULL)
   {
     *head=newNode;
      return;
   }

  struct node* temp=*head;

  while(temp->next!=NULL)
  {
      temp=temp->next;
  }
  
  temp->next=newNode;
}

void printList(struct node** head)
{
  if(*head==NULL)
   return;

   struct node* temp=*head;

   while(temp!=NULL)
   {
       printf("%x: %d \t",temp,temp->data);
       temp=temp->next;
    }
   printf("\n");
}

//get node based on value. You can also write a function to get based on node number
struct node* GetNode(struct node** head,int val)
{
   if(*head==NULL)
    return NULL;

   struct node* temp=*head;

   while(temp->next!=NULL)
   {
      if(temp->data==val)
        return temp;
      temp=temp->next;
   }
    
return NULL;
}

//connect the last node to this node within the loop
void MakeLoopAt(struct node** head,struct node** Node)
{
    struct node* temp=*head;
    if(*head==NULL)
     return;

    //10->20->30->40->NULL
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=*Node;//connect to the node,address of node
    printf("\nMake Looop at node:%x\n",*Node);     

}

int main()
{
    struct node* head=NULL;
    addNode(&head,10);
    addNode(&head,20);
    addNode(&head,30);
    addNode(&head,40);
    printList(&head);

    struct node *temp=GetNode(&head,20);
    printf("\n%d",temp->data);

    MakeLoopAt(&head,&temp);
   
    //int bhasloop=hasLoop(&head);
    //printf("\n Has Loop=%s\n",bhasloop==0?"No Loop":"Has Loop");

    int looplength=hasLoop(&head);
    printf("\n Loop length=%d\n",looplength);
}