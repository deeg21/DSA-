/*
   Dynamic stack
   Stack using Linked List.
   
*/

template<typename T>
struct Node
{
   Node<T>* prev=NULL;
   T value;
   delete Node() {}
   Node(T t)
   {
     value=t;prev=NULL;
   }
   T getValue(){return t;}
   
};

template<typename T>
class stacklist
{
   Node<T>*  top;
   int length;
   int max_size=100;
   public:
    stacklist()
    {
        top=new Node();
    }
    void push(T t)
    {
      if(length==max_size)
        {cout<<"\n Stack Overflow!!"<<"\n"; return;}
       Node* temp=new Node(t);//new node is the new top
       if(top==NULL)//check if top is null
        top=temp;
      else //save the current top, assign new node to top, assign old top to prev of new top 
      {
         Node* t=top;
         top=temp;
         top->prev=t;
         
       }
    
    }
    void pop()
    {
       if(top==NULL)
       {
         cout<<"\n Stack Underflow!!"<<"\n";return;
       }
       Node* temp=top;
       top=top->prev;
       delete temp;
     
    }
    int getLength()
    {
       return length;
    }
    void display()
    {
       if(top==NULL)
       {
         cout<<"\n Stack Underflow!!"<<"\n";return;
       }
       Node* temp=top;
       while(temp!=NULL)
       {
          cout<<temp->getValue()<<" ";
          
       }
       cout<<"\n";
    }
    ~stacklist()
    {
        Node* current=top;
        while(current->prev!=NULL)
        {
          Node* temp=current;
          current=current->prev;
          delete temp;
        }
    }

};

int main()
{
    stacklist<int> sl;
    sl.push(10);
    sl.push(20);
    sl.push(30);
    sl.push(40);
    s1.pop();
    s1.display();
}