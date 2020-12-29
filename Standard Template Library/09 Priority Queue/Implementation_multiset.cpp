A student is unaware of the C++ priority queue class, so he decides to design it on his own using set STL 
which he is aware of. Required priority queue should store integers. Higher the integer higher is it's 
priority.

He comes up with :

class myPQ
{
    multiset < int > underlyingDS;

public :
     int top ()
     {
         return *underlyingDS.rbegin();
     }
     void push (int x)
     {
         underlyingDS.insert(x);
     }
     void pop ()
     {
         underlyingDS.erase(*underlyingDS.rbegin());
     }
};