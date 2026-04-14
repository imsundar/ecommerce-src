#include "payment.h"
#include "gateway_client.h"
#include <iostream>

std::string processPayment(const std::string& userId, double amount) {
    std::cout << "PaymentService: Processing payment for " << userId << std::endl;

    try {
        std::string response = callPaymentGateway(amount);
        if (response == "OK") {
            return "SUCCESS";
        }
    } catch (const std::exception& e) {
        std::cout << "ERROR: " << e.what() << std::endl;

        // Retry logic
        try {
            std::cout << "Retrying payment..." << std::endl;
            std::string response = callPaymentGateway(amount);
            if (response == "OK") {
                return "SUCCESS";
            }
        } catch (...) {
            std::cout << "Retry failed." << std::endl;
        }
    }

    return "FAILED";
}
