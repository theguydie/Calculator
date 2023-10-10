#pragma once

#include "Token.h"
#include <vector>

class Parser {
private:
public:
	Parser() {};
	bool isBinMinus(std::string last_token) { return (!(last_token == "(")); } // binary: 4 - 3; non-binary: (-3) * 4
	bool isOperator(const char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^'); }
	bool isOperator(std::string c) { return (c == "+" || c == "-" || c == "*" || c == "/" || c == "(" || c == ")" || c == "^" || c == "sin" || c == "cos"); }
	std::vector<Token> Parse(std::string& expression);
};