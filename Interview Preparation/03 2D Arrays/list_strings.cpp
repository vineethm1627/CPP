#include <iostream>
using namespace std;

int main() {
    // read a list of strings and store them in a 2d array
    int n;
    cin >> n;
    cin.get();
    char arr[100][10000];
    for(int i = 0; i < n; i++) 
        cin.getline(arr[i], 10000);
    
    // print out all the strings
    for(int i = 0; i < n; i++) 
        cout << arr[i] << endl;

    return 0;
}