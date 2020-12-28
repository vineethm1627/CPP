#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    A single person has mutiple phone numbers
    Rahul --> 9973432990
    Rahul --> 9898999899
*/

int main() {

    unordered_map<string, vector<string> > phonebook;
    phonebook["Vineeth"].push_back("9110");
    phonebook["Vineeth"].push_back("0123");
    phonebook["Tanjiro"].push_back("1234");
    phonebook["Tenma"].push_back("4321");
    phonebook["Johan"].push_back("1111");

    // using for_each loop
    for(auto p : phonebook) {
        cout << "Name : " <<  p.first << endl;
        for(string s : p.second) 
            cout << "Number : " << s << endl;
        cout << "------------------------------\n";

    }
    // using for loop
    for(auto it = phonebook.begin(); it != phonebook.end(); it++) {
        cout << "Name : " <<  it->first << endl;
        for(string s : it->second) 
            cout << "Number : " << s << endl;
        cout << "------------------------------\n";
    }

    string name;
    getline(cin, name);
    if(phonebook.count(name) == 0) {
        cout << "Absent" << endl;
    }
    else {
        // print all the phone numbers
        for(string s : phonebook[name]) {
            cout << s << endl;
        }
    }

    return 0;
}