#include "Converter.h"
#include <stack>

std::vector<std::string> Converter::Converte(std::vector<Token> Parsed) {
	std::vector<std::string> res{};
	std::stack<Token> stack{};
	for (auto token : Parsed)
	{
		std::string str = token.getToken();
		if (token.getType() == 1)
		{
			res.push_back(str);
		}
		else if (str == ")")
		{
			while (stack.top().getToken() != "(")
			{
				res.push_back(stack.top().getToken());
				stack.pop();
			}
			stack.pop();
		}
		else if (str == "(")
		{
			stack.push(token);
		}
		else if (stack.empty() || (stack.top().getPrior() < token.getPrior()))
		{
			stack.push(token);
		}
		else
		{
			do
			{
				res.push_back(stack.top().getToken());
				stack.pop();
			} while (!(stack.empty() || (stack.top().getPrior() < token.getPrior())));
			stack.push(token);
		}
	}

	while (!stack.empty())
	{
		res.push_back(stack.top().getToken());
		stack.pop();
	}

	return res;
}