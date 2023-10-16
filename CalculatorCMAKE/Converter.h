#pragma once

#include "Token.h"
#include <vector>

class Converter {
public:
	Converter() {};
	std::vector<std::string> Converte(std::vector<Token> Parsed);
};