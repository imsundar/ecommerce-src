#include <string>
#include "../common/logger.h"

struct User {
    std::string userId;
    std::string name;
};

User getUser(const std::string& userId) {
    log("INFO", "UserService", "Retrieving user " + userId);
    return {userId, "Test User"};
}
