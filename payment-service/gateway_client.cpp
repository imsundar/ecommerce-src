#include "gateway_client.h"
#include "../common/config.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>

std::string callPaymentGateway(double amount) {
    std::cout << "Calling external payment gateway..." << std::endl;

    // Simulate delay (greater than timeout)
    int simulated_delay = 6;  // seconds

    if (simulated_delay > PAYMENT_TIMEOUT) {
        throw std::runtime_error("TimeoutError: Payment gateway did not respond within " 
                                + std::to_string(PAYMENT_TIMEOUT) + " seconds");
    }

    return "OK";
}
