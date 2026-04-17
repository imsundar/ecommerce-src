#include "gateway_client.h"
#include "../common/config.h"
#include "../common/logger.h"
#include <random>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <string>

std::string callPaymentGateway(double amount) {
    log("INFO", "GatewayClient", "Calling external payment gateway for amount=" + std::to_string(amount));

    // Simulate random delay
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);
    int simulated_delay = dis(gen);

    std::this_thread::sleep_for(std::chrono::seconds(simulated_delay));

    if (simulated_delay > PAYMENT_TIMEOUT) {
        throw std::runtime_error("TimeoutError: Payment gateway did not respond within " 
                                + std::to_string(PAYMENT_TIMEOUT) + " seconds");
    }

    log("INFO", "GatewayClient", "Payment gateway responded OK");
    return "OK";
}
