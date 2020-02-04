//
// Created by mxq on 2020/2/4.
//

#include "power.h"


bool invalid_input = false;

double Power(double base, int exponent){
    invalid_input = false;
    if (base == 0 && exponent < 0){
        invalid_input = true;
        return 0;
    }
    auto abs_exponent = (unsigned int)(exponent);
    if (exponent < 0)
        abs_exponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, abs_exponent);
    if (exponent < 0)
        result = 1.0 / result;
    return result;
}


double PowerWithUnsignedExponent(double base, unsigned int exponent){
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    // exponent为奇数
    if ((exponent & 0x1) == 1)
        result *= base;
    return result;
}
