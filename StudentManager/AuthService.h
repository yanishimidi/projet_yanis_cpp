#pragma once
#include "User.h"
#include <vector>
#include <string>

class AuthService {
public:
    static User* login(const std::vector<User>& users, const std::string& username, const std::string& password);
};
