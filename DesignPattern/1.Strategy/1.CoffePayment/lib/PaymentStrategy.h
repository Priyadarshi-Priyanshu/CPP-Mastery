#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
#include <memory>

// ----------------------------
// Strategy Interface
// ----------------------------
class PaymentStrategy {
public:
    virtual void pay(int amount) const = 0;
    virtual ~PaymentStrategy() = default;
};

// ----------------------------
// Concrete Strategies
// ----------------------------

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) const override;
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) const override;
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) const override;
};

#endif // PAYMENT_STRATEGY_H
