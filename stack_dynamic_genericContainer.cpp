/*
   Date: 27th June,2023
   Dynamic stack. You dont know the size of the data in advance. Implemented using vectors as default container. 
   The container type can be changed to list, deque, set which support these functions push_back, pop_back, empty,..
   Status: Tested for int and string data types
   Reference: stackoverflow.com, Templates the complete guide by David VandeVoorde, Nocilai M. Josuttis and Dorglas Gregor.
   Addison Wesley publications. Second Edition: 2018
   
   Important Notes: 
   1. For class templates,member functions are instantiated only if they are used.
   If a class template has static members, these are also instantiated once for each type for which the class template is used.

    
   
*/

#include<iostream>
#include<vector>
#include<cassert>
#include<string>
#include<deque>
#include<list>
using namespace std;

template<typename T,typename Cont=std::vector<T> >
class stack
{
   
   Cont mstack;   
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
      assert(!mstack.empty());
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

  /**************deque****************/
  /*std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its
    beginning and its end. In addition, insertion and deletion at either end of a deque never invalidates pointers or references to the rest of the elements.*/

  stack<string, std::deque<string>> s2;
  s2.push("Papa");
  s2.push("Jones");
  s2.push("Miranda");
  s2.display();
  s2.pop();
  cout<<"\n Top: "<<s2.top();
  
  /************list*************************/
  /*std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient*/
  stack<double, std::list<double>> s3;
  s3.push(3.142);
  s3.push(6.284);
  s3.push(12.568);
  s3.display();
  s3.pop();
  cout<<"\n Top: "<<s3.top();
}