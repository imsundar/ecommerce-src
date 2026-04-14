#include <iostream>
#include "../payment-service/payment.h"

// Forward declaration
struct Order {
    std::string orderId;
    std::string userId;
    std::string status;
};

Order createOrder(const std::string& userId);

int main() {
    std::string userId = "user123";
    double amount = 15000.0;

    std::cout << "API Gateway: Initiating checkout..." << std::endl;

    std::string paymentStatus = processPayment(userId, amount);

    if (paymentStatus == "SUCCESS") {
        Order order = createOrder(userId);
        std::cout << "Order placed successfully: " << order.orderId << std::endl;
    } else {
        std::cout << "Payment failed. Order not created." << std::endl;
    }

    return 0;
}
