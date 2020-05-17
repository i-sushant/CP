#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Student {
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string r)
    {
        firstname = f;
        lastname = l;
        rollno = r;
    }
    bool operator==(const Student& s) const
    {
        return rollno == s.rollno;
    }
};
class HashFn {
public:
    size_t operator()(const Student& s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};
int main()
{
    unordered_map<Student, int, HashFn> student_map;
    Student s1("Sushant", "Gupta", "50");
    Student s2("Sushant", "Gupta", "20");
    Student s3("Vishal", "Govind", "30");

    student_map[s1] = 100;
    student_map[s2] = 11;
    student_map[s3] = 45;

    for (auto s : student_map) {
        cout << s.first.firstname << " " << s.first.rollno << " " << s.second << endl;
    }
}