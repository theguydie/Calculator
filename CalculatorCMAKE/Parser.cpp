#include "Parser.h"

std::vector<Token> Parser::Parse(std::string& expression) {
	std::vector<Token> Parsed;
	std::string cur_token;
	std::string last_token = "";

	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] != ' ') {
			if (cur_token == "sin" || cur_token == "cos") {
				Parsed.push_back(Token(cur_token, 0));
				last_token = cur_token;
				cur_token = "";
			}
			if (isOperator(expression[i])) {
				if (expression[i] == '-') {
					if (!(isBinMinus(last_token)) || i == 0) {
						cur_token += '-';
						continue;
					}
				}
				if (cur_token != "")
					Parsed.push_back(Token(cur_token, 1)); //add as number
				last_token = expression[i];
				Parsed.push_back(Token(last_token, 0)); //add as operator
				cur_token = "";
			}
			else {
				cur_token += expression[i];
			}
		}
	}
	// last elem
	if (cur_token != "") Parsed.push_back(Token(cur_token, 1)); //add as number (case operator: last elem are also added)
	return Parsed;
}