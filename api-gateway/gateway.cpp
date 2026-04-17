#include <iostream>
#include <ctime>
#include "../payment-service/payment.h"
#include "../common/logger.h"

// Forward declarations
struct User {
    std::string userId;
    std::string name;
};

struct Order {
    std::string orderId;
    std::string userId;
    double amount;
    std::string status;
};

User getUser(const std::string& userId);
Order createOrder(const std::string& userId, double amount);

int main() {
    srand(time(NULL));
    std::string userId = "user123";
    double amount = 15000.0;

    log("INFO", "APIGateway", "Initiating checkout for user " + userId + " amount=" + std::to_string(amount));

    User user = getUser(userId);
    if (user.userId.empty()) {
        log("ERROR", "APIGateway", "User not found");
        return 1;
    }

    std::string paymentStatus = processPayment(userId, amount);

    if (paymentStatus == "SUCCESS") {
        Order order = createOrder(userId, amount);
        log("INFO", "APIGateway", "Order placed successfully: " + order.orderId);
    } else {
        log("ERROR", "APIGateway", "Payment failed. Order not created.");
    }

    return 0;
}
