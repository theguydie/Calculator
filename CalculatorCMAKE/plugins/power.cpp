#include "power.h"

#include <stdexcept>
#include <cmath>

extern "C" double Pow(double x, double y)
{
    if (x < 0) throw std::runtime_error("base of 'x^y'-expression must be >= 0");
    return std::pow(x, y);
}