#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// while using custom classes the system doesn't know how to compare the two objects.
// comparators makes the code generic that works on all custom classes too.
// we need to specify on what param to compare upon.
// this is the ultimate search function.
// this is how the STL functions are implemented.

// return type is ForwardIterator
template<class ForwardIterator, class T, class Compare>
ForwardIterator search(ForwardIterator start, ForwardIterator end, T key, Compare cmp) {
    while(start != end) {
        // dereferencing.
        if(cmp(*start, key)) {
            return start; //start is the index
        }
        start++;
    }
    // range is 0 to n - 1, so returning n means element not found.
    return end;
}

//Note: The class definition ends with a semicolon ";". 
class Book {
    public:
        string name;
        int price;
    //default ctor
    Book() {
        name = "";
        price = 0;
    }

    //parameterized ctor
    //this refers to the currently active object.
    Book(string name, int price) {
        this->name = name;
        this->price = price;
    }

};

class BookCompare {
    // operator "()" overloading.
    public:
        bool operator()(Book a, Book b) {
            //we want to compare on the basis of name of the book only.
            if(a.name == b.name) {
                return true;
            }
            return false;
        }
};

int main() {
    Book b1("C++", 100); //let's assume old edition.
    Book b2("Python", 120);
    Book b3("Java", 130);

    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);

    Book booktofind("C++", 110); //let's assume new edition. 

    //looks like a function call but it is indeed an object.
    //functional object / functor.
    BookCompare cmp;
    if(cmp(b1, booktofind)) {
        cout << "True same books" << endl;
    }
    else {
        cout << "False different books";
    }
    
    //instead of specifying the type of it, simply use auto
    list<Book>::iterator it = search(l.begin(), l.end(), booktofind, cmp);
    if(it == l.end()) {
        cout << "Book not found";
    }
    else {
        cout << "Book found";
    }

    return 0;
}

/*
 Note : 
    1) Templates : gives freedom from datatype.
    2) Iterator : gives freedom from data structure / container.
    3) Comparator : gives freedom from different types of operations on the data.
*/