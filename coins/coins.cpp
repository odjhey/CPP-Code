#include "../coins/coins.h"

#include <iostream>
#include <fstream>

Coins::Coins(const char *file)
{
    std::ifstream in(file);

    int num;
    while(in >> num)
    {
        int num_coins = 0;
        int rest = num%5;
        num_coins = num/5;
        if(rest > 0) {
            num = rest;
            if(num >= 3) {
                rest = num%3;
                num_coins += num/3;
                if(rest > 0)
                    num_coins += rest;
            } else {
                num_coins += num;
            }
        }
        std::cout << num_coins << std::endl;
    }
}
