struct student{
    string name;
    float cgpa;
    student(string name, float cgpa){
        this -> name = name;
        this -> cgpa = cgpa;
    }
};

struct comp{
    bool operator () (const student& x, student y) {
        return x.name < y.name;
    }
};

set < student, comp > batch;