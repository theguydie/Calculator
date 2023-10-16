#pragma once

#include "Parser.h"
#include "Converter.h"
#include "Loader.h"

class Calculator {
private:
	Parser pars;
	Converter conv;
	Loader load;
public:
	Calculator() : pars(), conv() {};
	double Calculator::from_chars(std::string s);
	double Calculate(std::string expression);
};