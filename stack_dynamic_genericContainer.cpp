/*
   Date: 27th June,2023
   Dynamic stack. You dont know the size of the data in advance. Implemented using vectors as default container. 
   The container type can be changed to list, deque, set which support these functions push_back, pop_back, empty,..
   Status: Tested for int and string data types
   Reference: stackoverflow.com, Templates the complete guide by David VandeVoorde, Nocilai M. Josuttis and Douglas Gregor.
   Addison Wesley publications. Second Edition: 2018
   
   Important Notes: 
   1. For class templates,member functions are instantiated only if they are used.
   If a class template has static members, these are also instantiated once for each type for which the class template is used.
2.Alias: defining a new name for an existing type 
      typedef Stack<int> IntStack; //typedef
       or
       using IntStack = Stack<int>; //alias declaration

    3. Alias template: An alias declaration can be templated to provide a convenient name for a family of types. 
       This is also available since C++11 and is called an alias template.
       The following alias template DequeStack, parameterized over the element type T, expands to a Stack that 
       stores its elements in a std::deque:
       template<typename T>
       using DequeStack = Stack<T, std::deque<T>>;
    4. Alias Templates for member types
       A definition such as
       template<typename T>
       using MyTypeIterator = typename MyType<T>::iterator;
        allows the use of

        MyTypeIterator<int> pos;         instead of the following:
       typename MyType<T>::iterator pos;
      5. Automatic Template type deduction is done by passing a single argument to the constructor, so the compiler can deduce the type.
      6. However, if value is passed by reference to the constructor, the parameter doesn’t decay, which is the term for the mechanism to convert a raw array type to the corresponding raw pointer type. so pass by reference constructor  doesnt work for string type argument deduction.
          Therefore, we have used a pass by value in constructor with move semantics, to avoid copying.(page 42,Templates the complete guide)
   
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
   stack() = default;//default constructor is activated explicitely, since we have provided our own constructor.

  // stack(const T& t):mstack({t}){}
   //we are passing only one element t in vector initialiser list to help the compiler to deduce the type of argument.
    //so curly braces are used to pass initialiser list to container/vector

  stack(const T t):mstack({std::move(t)}){}//pass by value works for template type deduction for string data types.otherwise the compiler cannot convert raw array to raw pointer.

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
   std::cout<<"************Integer Stack*********************************\n";
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

   std::cout<<"\n***************Automatic Template type deduction*********************\n";
    stack s01=9;
    std::cout<<"Integer Stack: ";
    s01.display();

   stack s02=2.56;
   std::cout<<"Double type Stack: ";
   s02.display();

   stack s03="Johny Lever!!";
   std::cout<<"String stack: ";
   s03.display();
 
  std::cout<<"\n/******string stack*******************/\n";
  stack<string> s1;
  s1.push("hello");
  s1.push("Deepika");
  s1.push("Miranda");
  s1.display();
  s1.pop();
  cout<<"\n Top: "<<s1.top(); 

  std::cout<<"/**************Stack Using deque****************/\n";
  /*std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its
    beginning and its end. In addition, insertion and deletion at either end of a deque never invalidates pointers or references to the rest of the elements.*/

  stack<string, std::deque<string>> s2;
  s2.push("Papa");
  s2.push("Jones");
  s2.push("Miranda");
  s2.display();
  s2.pop();
  cout<<"\n Top: "<<s2.top();
  
  std::cout<<"/************Stack Using list*************************/\n";
  /*std::list is a container that supports constant time insertion and removal of elements from anywhere in the container. Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient*/
  stack<double, std::list<double>> s3;
  s3.push(3.142);
  s3.push(6.284);
  s3.push(12.568);
  s3.display();
  s3.pop();
  cout<<"\n Top: "<<s3.top();
}
