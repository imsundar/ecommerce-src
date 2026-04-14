#ifndef CONFIG_H
#define CONFIG_H

#include <string>

const std::string ENV = "QA";
const int PAYMENT_TIMEOUT = 5;  // 🚨 Root cause
const int RETRY_COUNT = 1;

#endif
