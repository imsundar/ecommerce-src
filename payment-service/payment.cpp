#include "payment.h"
#include "gateway_client.h"
#include "../common/logger.h"
#include "../common/config.h"
#include <string>

std::string processPayment(const std::string& userId, double amount) {
    log("INFO", "PaymentService", "Processing payment for " + userId + " amount=" + std::to_string(amount));

    for(int i = 0; i < RETRY_COUNT; i++) {
        try {
            log("INFO", "PaymentService", "Attempt " + std::to_string(i+1) + " calling gateway");
            std::string response = callPaymentGateway(amount);
            if (response == "OK") {
                log("INFO", "PaymentService", "Payment successful");
                return "SUCCESS";
            }
        } catch (const std::exception& e) {
            log("ERROR", "PaymentService", e.what());
            if (i < RETRY_COUNT) {
                log("WARN", "PaymentService", "Retrying...");
            }
        }
    }
    log("ERROR", "PaymentService", "Payment failed after all attempts");
    return "FAILED";
}
