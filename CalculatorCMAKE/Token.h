#pragma once

#include <string>
#include <unordered_map>

class Token {
private:
	std::string token;
	int type; // 0 - operator, 1 - number
	std::unordered_map<std::string, int> priorities = {
		{")", 0},
		{"(", 0},
		{"+", 2},
		{"-", 2},
		{"*", 3},
		{"/", 3},
		{"^", 4},
		{"sin", 4},
		{"cos", 4}
	};
public:
	Token(std::string _token, int _type) : token(_token), type(_type) {};
	int getType() { return type; }
	int getPrior() { return priorities[token]; }
	std::string& getToken() { return token; }
};