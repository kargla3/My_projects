#include <iostream>
#include "Currency.h"
#include "Cash_register.h"

int main()
{
    Cash_register reg(Currency::load_currencies("prices.txt"));
    Customer customer("wallet.txt");
    reg.menu(customer);
}