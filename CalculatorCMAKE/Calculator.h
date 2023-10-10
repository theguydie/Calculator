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
	double from_chars(std::string s);
	Calculator() : pars(), conv() {};
	double Calculate(std::string expression);
};