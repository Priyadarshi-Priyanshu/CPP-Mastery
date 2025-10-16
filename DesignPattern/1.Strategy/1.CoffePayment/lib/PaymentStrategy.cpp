#include "PaymentStrategy.h"

void CreditCardPayment::pay(int amount) const {
    std::cout << "Paid ₹" << amount << " using Credit Card.\n";
}

void PayPalPayment::pay(int amount) const {
    std::cout << "Paid ₹" << amount << " using PayPal.\n";
}

void UpiPayment::pay(int amount) const {
    std::cout << "Paid ₹" << amount << " using UPI.\n";
}
