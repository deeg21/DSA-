
/*
    Date:13th July, 2023
    Count the number of primes. seperate the primes from non primes.
    Reference Techdose.co.in

    
*/

/*
   We have to find the number of primes less than N. 
   1. Declare an array of size N+1. Initially set all slots to true.
   
    iterate through numbers 2 to N;

   2.if i is a prime number, then all multiples of i are non-prime. So cancel them.(lets say 2,3,5,7,9,11,13...)
   4. else if i is not prime so some smaller number might have divided i and marked all multiples of i.(e.g 4,6,8,10...)
   5. Repeat steps till N
  
   Improvement to above algorithm:

    1. The above algorithm needs only N/2 iterations. after N/2 there will be no multiples of prime numbers. All multiples have been marked already.
        so after N/2 we can just get the non cancelled numbers as prime numbers.(if N=19, N/2=9.5=9. so no need to check above 9.Just get unmarked numbers 11,13,17..)
    2. if N is a non prime number then it is guaranteed, it can be expressed as mutiples of 2 numbers less than equal to square root N and another greater than equal to sqaure root N.
       
   Time complexity will be N/2 + N/3 + N/5 + N/7 + N/11....N/P=Harmonic progression of sum of primes??=NloglogN.
*/
//#include<iostream>
//#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
    cout<<"Enter the Number:\n";
    cin>>n;
    
    vector<bool> prime_vec(n+1,true);
     
   for(int i=2;i<sqrt(n);i++)//ending condition can be square root n, rather than n/2.
   {
      if(prime_vec[i]==true)//if it is not changed, then its a prime.
      {
         for(int j=i*i;j<=n;j+=i)//if i=2, j is multiples of 2: 4,6,8,10...
                             //if i=3, j is 3*2=6,9,12, 
                             //if i=5, j is 5*2=10, 15,20...
         /*Optimisation 2: we can set the start for j=i*i rather than i*2. If i=5, then 5*2,5*3, 5*4 have already been covered by numbers below it. so we can start directly from 5*5*/

         {
             prime_vec[j]=false;
         }
      }
   }
   
   for (int i=2;i<=n;i++)
   {
     if(prime_vec[i])
        cout<<i<<" ";
   }
   cout<<"\n";
}