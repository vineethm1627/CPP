/*
    Bucket sort to sort an array of students based on their marks.

    Bucket sort is useful when input is uniformly distributed over a range.
*/ 
#include <iostream>
#include <vector>
using namespace std;
 
class student {
    public:
        string name;
        int marks;
}; 
// marks are in the range 0 - 100
void bucketSort(student *s, int n) {
    // create an array of vectors.
    // O(n) time.
    vector<student> v[101];
    for(int i = 0; i < n; i++) {
        int marks = s[i].marks;
        v[marks].push_back(s[i]);
    }

    // iterate over the vector and print the students
    for(int i = 100; i >= 0; i--) {
        for(auto it = v[i].begin(); it != v[i].end(); it++) 
            cout << (*it).marks << " " << (*it).name << "\n";
    }
}
 
int main() {
    
    int n;
    cin >> n;

    student s[n];
    for(int i = 0; i < n; i++) 
        cin >> s[i].marks >> s[i].name;
    
    bucketSort(s, n);
    
    return 0;
}