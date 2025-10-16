#include "CoffeeShop.h"

void CoffeeShop::setPaymentStrategy(std::unique_ptr<PaymentStrategy> s) {
    strategy = std::move(s);
}

void CoffeeShop::checkout(int amount) const {
    if (strategy)
        strategy->pay(amount);
    else
        std::cout << "Payment method not selected.\n";
}
