#pragma once
#include <string>

enum Role { ADMIN, PROF, STUDENT };

class User {
private:
    int id;
    std::string username;
    std::string password;
    Role role;

public:
    User(int id, std::string u, std::string p, Role r)
        : id(id), username(u), password(p), role(r) {}

    int getId() const { return id; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    Role getRole() const { return role; }
};
