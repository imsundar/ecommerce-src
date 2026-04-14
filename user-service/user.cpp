#include <string>

struct User {
    std::string userId;
    std::string name;
};

User getUser(const std::string& userId) {
    return {userId, "Test User"};
}
