#include <iostream>
#include <queue>
using namespace std;

class Person {
    string name;
    int age;

    public:
    Person() {
        // it is necessary to define the default ctor in case of param ctor.
    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    // custom comparator by overloading () operator
    bool operator()(Person P1, Person P2) {
        return P1.getAge() < P2.getAge();
    }
};

// maxHeap
// give priority based on lesser age
// class PersonCompare {
//     public:
//     bool operator()(Person p1, Person p2) {
//         return p1.getAge() < p2.getAge();
//     }
// };

int main() {

    int n;
    cin >> n;
    // priority_queue<Person, vector<Person>, PersonCompare> pq;
    priority_queue<Person, vector<Person>, Person> pq; 
    for(int i = 0; i < n; i++) {
        string name; 
        int age;
        cin >> name >> age;
        Person p(name, age);
        // push this object inside a priority queue
        pq.push(p);
    }

    // give award to oldest people
    cout << "Order of awards receival " << endl; 
    while(!pq.empty()) {
        Person p = pq.top();
        cout << p.getName() << " " << p.getAge() << endl;
        pq.pop();
    }
    return 0;
}