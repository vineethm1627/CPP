#include <iostream>
using namespace std;

int main() {

    char a[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    int arr[10] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Size of the character array : " << n << endl;
    cout << a << endl; // prints abcde ie. the entire content of the array.
    // the array is printed unless the null character is encountered.
    cout << arr << endl; // prints the address of the first element

    // cout << "Enter any string : ";
    // char s[100];
    // cin >> s;
    // cout << s;

    char s1[] = {'h', 'e', 'l', 'l', 'o'}; // doesnt terminate with a null and thereby can result in garbage values when displayed.
    char s2[] = "hello";
    cout << "s1 : " << s1 << endl; // s1 : hello☺ ie. garbage values when not terminated with '\0'
    cout << "s2 : " << s2 << endl; // s2 : hello

    cout << "size s1 : " << sizeof(s1) << endl; // 5
    cout << "size s2 : " << sizeof(s2) << endl; // 6 ie. +1 for the null character

    cout << s1[0] << endl;
    cout << s2[0] << endl;

    for(char i : s2) {
        cout << i; 
    }
    cout << endl;
    return 0;
}