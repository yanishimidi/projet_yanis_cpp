#pragma once
#include <string>

class Course {
private:
    int id;
    std::string name;

public:
    Course(int i, std::string n) : id(i), name(n) {}
    int getId() const { return id; }
    std::string getName() const { return name; }
};
