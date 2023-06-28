/*
   Date: 27th June,2023
   Dynamic stack. You dont know the size of the data in advance. 
   Status: Tested for int and string data types
   Reference: stackoverflow.com, Templates the complete guide by David VandeVoorde, Nocilai M. Josuttis and Dorglas Gregor.
   Addison Wesley publications. Second Edition: 2018
   
   Important Notes: 
   1. For class templates,member functions are instantiated only if they are used.
   If a class template has static members, these are also instantiated once for each type for which the class template is used.

   2. 
    void foo(Stack<int> const& s) // parameter s is int stack
    {
      using IntStack = Stack<int>; // IntStack is another name for Stack<int>
      Stack<int> istack[10]; // istack is array of 10 int stacks
      IntStack istack2[10]; // istack2 is also an array of 10 int stacks (same type)
      ...
    }
   
   
   
*/

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class stack
{
   
   vector<T> mstack;   
public:
   stack():mstack(){}
  

   void push(const T& val)
   {
      mstack.push_back(std::move(val));
   }

   // Get the element at the top
    T& top()
    { 
        return mstack.back();
    } 


    // Get the element at the top
    const T& top() const
    { 
        return mstack.back();
    }
 
   void pop() noexcept
   {
      assert(!mstack.empty())
      mstack.pop_back();
   }

   bool empty() const
   {
      return mstack.empty();
   }

   void display()
   {
     for(auto itr:mstack)
     {
       cout<<itr<<" ";
     }
     cout<<"\n";
   }
  
};


int main()
{
   stack<int> s0;
   s0.push(20);
   s0.pop();
   s0.push(20);
   s0.push(30);
   s0.push(40);
   s0.push(50);
   s0.display();
   cout<<"\n Top: "<<s0.top(); 
   s0.pop();
   cout<<"\n Top: "<<s0.top(); 


  /******string*******************/
  stack<string> s1;
  s1.push("hello");
  s1.push("Deepika");
  s1.push("Miranda");
  s1.display();
  s1.pop();
  cout<<"\n Top: "<<s1.top(); 
  
}