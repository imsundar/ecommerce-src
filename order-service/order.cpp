#include <iostream>
#include <string>

struct Order {
    std::string orderId;
    std::string userId;
    std::string status;
};

Order createOrder(const std::string& userId) {
    std::cout << "OrderService: Creating order..." << std::endl;

    return {"ORD12345", userId, "CONFIRMED"};
}
