#include "Calculator.h"

#include <charconv>
#include <stdio.h>
#include <system_error>
#include <stack>
#include <iostream>

double Calculator::from_chars(std::string s) {
	try {
		return std::stod(s);
	}
	catch (const std::invalid_argument& e) {
		throw std::runtime_error("Error: invalid argument '" + s + "'");
	}
}

double Calculator::Calculate(std::string expression) {
	auto Parsed = pars.Parse(expression);
	auto Converted = conv.Converte(Parsed);
	std::stack<double> exprs;
	for (std::string token : Converted) {
		//case operator
		if (pars.isOperator(token)) {
			double expr2 = exprs.top();
			exprs.pop();

			if (token == "+") {
				double expr1 = exprs.top();
				exprs.pop();
				exprs.push(expr1 + expr2);
			}
			else if (token == "-") {
				double expr1 = exprs.top();
				exprs.pop();
				exprs.push(expr1 - expr2);
			}
			else if (token == "*") {
				double expr1 = exprs.top();
				exprs.pop();
				exprs.push(expr1 * expr2);
			}
			else if (token == "/") {
				double expr1 = exprs.top();
				exprs.pop();
				if (expr2 == 0) throw std::runtime_error("division by 0");
				exprs.push(expr1 / expr2);
			}
			else if (token == "^") {
				auto Pow = load.loadFunction<double(double, double)>("Pow");

				double expr1 = exprs.top();
				exprs.pop();
				exprs.push(Pow(expr1, expr2));
			}
			else if (token == "sin") {
				auto Sin = load.loadFunction<double(double)>("Sin");

				exprs.push(Sin(expr2));
			}
			else if (token == "cos") {
				auto Cos = load.loadFunction<double(double)>("Cos");

				exprs.push(Cos(expr2));
			}
		}
		//case number
		else {
			exprs.push(from_chars(token));
		}
	}
	return exprs.top();
}