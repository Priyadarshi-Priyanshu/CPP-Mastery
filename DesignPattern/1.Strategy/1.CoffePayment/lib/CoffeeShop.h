#ifndef COFFEE_SHOP_H
#define COFFEE_SHOP_H

#include "PaymentStrategy.h"

// ----------------------------
// Context Class
// ----------------------------
class CoffeeShop {
private:
    std::unique_ptr<PaymentStrategy> strategy;

public:
    CoffeeShop() = default;
    ~CoffeeShop() = default;

    // Disable copy semantics (unique_ptr can't be copied)
    CoffeeShop(const CoffeeShop&) = delete;
    CoffeeShop& operator=(const CoffeeShop&) = delete;

    // Allow move semantics
    CoffeeShop(CoffeeShop&&) noexcept = default;
    CoffeeShop& operator=(CoffeeShop&&) noexcept = default;

    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> s);
    void checkout(int amount) const;
};

#endif // COFFEE_SHOP_H
