// build Hashmap for custom class
#include <iostream>
#include <unordered_map>
using namespace std;

class Student {
    public:
        string firstName;
        string lastName;
        string rollNo;

        Student(string firstName, string lastName, string rollNo) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->rollNo = rollNo;
        }
        // operator overloading
        // we assume the roll number is unique
        bool operator==(const Student &s) const{
            return rollNo == s.rollNo ? true: false;
        }
};

// define a hash function
class HashFunc {
    public:
        size_t operator()(const Student &s) const{
            return s.firstName.length() + s.lastName.length();
        }
};


int main() {

    unordered_map<Student, int, HashFunc> hashMap;

    Student s1("Vineeth", "M", "010");
    Student s2("Vineeth", "Jain", "023");
    Student s3("Tanjiro", "Kamada", "111");
    Student s4("Kenzo", "Tenma", "001");
    Student s5 = Student("Johan", "Liebert", "002");

    // add student -> marks to hashMap
    hashMap.insert({s1, 100});
    hashMap[s2] = 120;
    hashMap.insert(make_pair(s3, 11));
    hashMap[s4] = 150;
    hashMap[s5] = 140;

    // iterate over the hashMap
    for(auto s : hashMap) {
        cout << s.first.firstName << " " << s.first.lastName << " " << s.first.rollNo << endl;
        cout << "Marks : " << s.second << endl;
        cout << "============================\n";
    }

    // find the marks of student s4
    cout << hashMap[s4] << endl;

    return 0;
}