#include "AuthService.h"

User* AuthService::login(const std::vector<User>& users, const std::string& username, const std::string& password) {
    for (const auto& u : users) {
        if(u.getUsername() == username && u.getPassword() == password)
            return new User(u);
    }
    return nullptr;
}
