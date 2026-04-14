# E-commerce Platform (C++ Microservices Simulation)

## Services:
- API Gateway
- Payment Service
- Order Service
- User Service

## Known Issue:
Payment failures due to timeout in payment gateway.

## Root Cause:
Timeout configured too low (5 seconds)

## Build:
g++ api-gateway/gateway.cpp payment-service/payment.cpp payment-service/gateway_client.cpp -o app
