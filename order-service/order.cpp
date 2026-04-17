#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../common/logger.h"

struct Order {
    std::string orderId;
    std::string userId;
    double amount;
    std::string status;
};

Order createOrder(const std::string& userId, double amount) {
    log("INFO", "OrderService", "Creating order for " + userId + " amount=" + std::to_string(amount));

    return {"ORD" + std::to_string(rand()), userId, amount, "CONFIRMED"};
}
