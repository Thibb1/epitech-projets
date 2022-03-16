/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4011.hpp"

nts::C4011::C4011()
{
    _nbPin = 14;
}

nts::C4011::~C4011()
{
}

void nts::C4011::simulate(size_t pin)
{
    switch (pin) {
        case 3:
            _values[3] = Gate::Nand(computePin(1), computePin(2));
            break;
        case 4:
            _values[4] = Gate::Nand(computePin(5), computePin(6));
            break;
        case 10:
            _values[10] = Gate::Nand(computePin(8), computePin(9));
            break;
        case 11:
            _values[11] = Gate::Nand(computePin(12), computePin(13));
            break;
        default:
            throw std::out_of_range("PinError: pin out of range");
    }
}

void nts::C4011::dump() const
{
    std::cout << "\n    03: " << getTristateString(3);
    std::cout << "\n    04: " << getTristateString(4);
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    11: " << getTristateString(11) << std::endl;
}