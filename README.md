# E-commerce Platform (C++ Microservices Simulation)

## Services:
- API Gateway
- Payment Service
- Order Service
- User Service

## Known Issue:
Payment failures occur more frequently due to insufficient retry attempts caused by an off-by-one error in the retry logic.

## Root Cause:
Retry loop condition 'i < RETRY_COUNT' performs one fewer attempt than configured.

## Build:
g++ api-gateway/gateway.cpp payment-service/payment.cpp payment-service/gateway_client.cpp order-service/order.cpp user-service/user.cpp common/logger.cpp -o app
