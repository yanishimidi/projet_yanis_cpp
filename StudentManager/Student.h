#pragma once
#include <string>

class Student {
private:
    int id;
    std::string name;
    std::string email;

public:
    Student(int i, std::string n, std::string e)
        : id(i), name(n), email(e) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};
