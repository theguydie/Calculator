// CalculatorCMAKE.cpp: определяет точку входа для приложения.
//

#include "Calculator.h"

#include <iostream>
#include <string>

int main() {
	std::string expr;
	std::getline(std::cin, expr);

	Parser pars;
	Converter conv;
	Calculator calc;

	while (expr != "exit") {

		//parser test
		/*std::vector<Token> tokens = pars.Parse(expr);
		std::cout << tokens.size() << std::endl;
		for (int i = 0; i < tokens.size(); i++) {
			std::cout << "token: " << tokens[i].getToken() << std::endl;
		}
		std::cout << std::endl;
		*/

		//converter test
		/*
		auto converted = conv.Converte(tokens);
		for (int i = 0; i < converted.size(); i++) {
			std::cout << "sorted: " << converted[i] << std::endl;
		}
		std::cout << std::endl;
		*/

		//calculator test
		Calculator calc;
		try {
			std::cout << "result is : " << calc.Calculate(expr) << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
		std::getline(std::cin, expr);
	}

	return 0;
}
