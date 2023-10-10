#include "Calculator.h"

#include <stack>
#include <iostream>

double Calculator::from_chars(std::string s) {
	bool flag = true;
	int sign = 1;
	double res = 0;
	int i = 0;
	for (auto c : s) {
		if (c == '.') flag = false;
		else if (c == '-') sign = -1;
		else {
			res *= 10;
			res += double(int(c) - int('0'));
			if (!flag) i++;
		}
	}
	return sign * res / std::pow(10, i);
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
				exprs.push(expr1 / expr2);
			}
			else if (token == "^") {
				auto Pow = load.loadFunction<double(double, double)>("plugins/power.dll", "Pow");

				double expr1 = exprs.top();
				exprs.pop();
				exprs.push(Pow(expr1, expr2));
			}
			else if (token == "sin") {
				auto Sin = load.loadFunction<double(double)>("plugins/sinus.dll", "Sin");

				exprs.push(Sin(expr2));
			}
			else if (token == "cos") {
				auto Cos = load.loadFunction<double(double)>("plugins/cosinus.dll", "Cos");

				exprs.push(Cos(expr2));
			}
			//case number
		}
		else {
			exprs.push(from_chars(token));
		}
	}
	return exprs.top();
}