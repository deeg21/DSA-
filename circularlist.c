#include<stdio.h>
#include<stdlib.h>

//enum bool{FALSE=0,TRUE=0} ;

struct node
{
   int data;
   struct node* next;
};

//struct node* head=NULL;
void addNodeLast(struct node**head,int val)
{
   struct node* newNode=(node*)malloc(sizeof(struct node));
   newNode->next=*head;//circular queue, the last node points to the first node
   newNode->data=val;
   
   if(*head==NULL)
   {
     newNode->next=newNode;
     *head=newNode;
      return;
   }

  struct node* temp=*head;//Get the head in the linked list

  while(temp->next!=*head)
  {
      temp=temp->next;
  }
  
  temp->next=newNode;
}

/*
    Its a circular linked list.
    Last Node connects to the first Node.
    Insert a node in the beginning.
    1.Create a new node with the value given.
    2.Check if the head node is NULL. if yes, add the new node to it
      and point it to itself since its a circular node.
    3.If Head node is not NULL, Save the head node in temporary node,
      point the head node to newnode. Point the newnode to old head node saved in temporary.
    4.go the last node, and point it to new head.

*/
void addNodeFirst(struct node**head,int val)
{
   
   struct node* newNode=(node*)malloc(sizeof(struct node));
   newNode->data=val;
   newNode->next=NULL;
   if(*head==NULL)
   {
       newNode->next=newNode;
       *head=newNode;
       //*head->next=*head;//circular list
       return;
   }
   
   struct node* temp=*head;
   
   while(temp->next!=*head)
   {
     temp=temp->next;
   }
   temp->next=newNode;//point temp/last node to the New Head

   temp=*head;//now save head in temp.
   *head=newNode;
   (*head)->next=temp;//point to the old head;
    
}

/*
   Search the node with the required value. 
  
   That probably means that duplicates dont exist in the linked list.
   Return Value:0 if node with value not found
               :1 if node with value found
*/


int SearchNode(struct node** head, int val)
{
   struct node* temp=*head;
  
  if(*head==NULL)
    return 0;

   do
   {
       if(temp->data==val)
        return 1;
      temp=temp->next;
   }while(temp!=*head);

   return 0;
   
}

//delete Node by value
int DeleteNode(struct node** head, int value)
{
   //case 1: if head node is null, i.e linked list is empty
   if(*head==NULL)
    return 0;

  //case 2:The value is in the head node.There is no previous node. so this needs to be deleted differently. There may be any number of nodes in the list,one or more.
  //if there is only one node, then head is pointing to head. so we have to check that.
  if((*head)->data==value)
  { 
     if((*head)->next==*head)//only one node with *head pointing to *head, no need to save next node value.
     {
       free(*head);
       return 1;
     }
     else
     {
       /*if the "value" is in the first node, and the linked list has more than 1 node.*/
         /*Save the next node pointed by head*/
       struct node *temp=*head;
       
        
        //get the last node, and point it to new head
        while(temp->next!=*head)//previous head 
        {
           temp=temp->next;
        }
        temp->next=(*head)->next;//point temp/last node, to the new head
        free(*head);//delete the old head
        *head=temp->next;//new head, which is node next to head.
        return 1;
     }
      
   }
   //case 3: any node, other than head node. There are atleast 2 nodes in the linked list here and The value does not lie in head node.
   struct node *temp=*head;
   do
   {
      //case 3.1
     /*Suppose there are 2 nodes in the linked list, the second one points to head, i.e the first one i.e head node in a cicular fashion*/
     /*The value is present in the second node. The second node is pointing to first one i.e head . 
       So temp is checking the second node for "value" when temp is pointing to first node. */
       /*Even if the node deleted is the last node, value of next=*head node will be saved*/
     if(temp->next->data==value)
     {
        struct node* del=temp->next;//save the middle node
        temp->next=temp->next->next;//bypass the middle node which hold the value
        free(del);
        return 1;  
     }
     /*if there were only 2 nodes, initialy, the second one has been deleted,
      The head/temp node is pointing to itself, this iteration will just loop,it has no deleterious effect. temp is also head, and temp->next is also head, so code will exit in next iteration.*/
  
     temp=temp->next;
   
   }while(temp->next!=*head);

   
  return -1;//Indicates that no node not found with given value.

  
}


void printList(struct node** head)
{
  if(*head==NULL)
   return;

   struct node* temp=*head;
   
   do
   {
       printf("%x: %d \t",temp,temp->data);
       temp=temp->next;
    }while(temp!=*head);//last node points to the head

   printf("\n");
}

int main()
{
   struct node* head=NULL;
   addNodeLast(&head,-11);
   //addNodeFirst(&head,10);
   printList(&head);
   addNodeLast(&head,-22);
   addNodeLast(&head,-33);
   addNodeLast(&head,-44);
   printList(&head);

   addNodeFirst(&head,100);
   addNodeFirst(&head,200);
   addNodeFirst(&head,300);
   addNodeFirst(&head,400);
   printList(&head);

   addNodeLast(&head,-10);
   printList(&head);
   
   addNodeLast(&head,-20);
   printList(&head);

   addNodeLast(&head,-30);
   printList(&head);

   printf("\n %s \n",SearchNode(&head,-22)==1?"true":"false");
   //enum bool{false, true};
   //printf("\n enum %d,%d\n",false,true);
   printf("\n %s \n",DeleteNode(&head,100)==1?"Node Deleted!!":"Not Found/empty List!!");
   printList(&head);
    printf("\n %s \n",DeleteNode(&head,200)==1?"Node Deleted!!":"Not Found/empty List!!");
   printList(&head);
    printf("\n %s \n",DeleteNode(&head,-30)==1?"Node Deleted!!":"Not Found/empty List!!");
   printList(&head);
   printf("\n %s \n",DeleteNode(&head,-20)==1?"Node Deleted!!":"Not Found/empty List!!");
   printList(&head);
    
}