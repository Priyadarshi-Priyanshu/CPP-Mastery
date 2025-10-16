#include "CoffeeShop.h"
#include <memory>


int main() {
    CoffeeShop shop;

    shop.setPaymentStrategy(std::make_unique<CreditCardPayment>());
    shop.checkout(250);

    shop.setPaymentStrategy(std::make_unique<PayPalPayment>());
    shop.checkout(350);

    shop.setPaymentStrategy(std::make_unique<UpiPayment>());
    shop.checkout(150);
}
