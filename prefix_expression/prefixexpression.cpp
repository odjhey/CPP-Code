/*
 * prefixexpression.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: Koe
 */

#include "prefixexpression.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

std::vector<std::string> prefix_expression::split(const std::string &text, const char delim)
{
	std::vector<std::string> vec;
	std::stringstream ss(text);
	std::string temp;
	while(std::getline(ss, temp, delim))
	{
		vec.push_back(temp);
	}
	return vec;
}

prefix_expression::prefix_expression(const char *file)
{
	std::ifstream stream(file);
	std::string line;
	while(std::getline(stream, line))
	{
		std::stack<double> s;
		std::vector<std::string> input = split(line, ' ');

		for(int i = input.size()-1; i >= 0; --i)
		{
			std::string &c = input[i];
			if(c == "*" || c == "/" || c == "+")
			{
				double op1 = s.top();
				s.pop();
				double op2 = s.top();
				s.pop();
				double res = 0;
				if(c == "*") res = op1 * op2;
				if(c == "/") res = op1 / op2;
				if(c == "+") res = op1 + op2;
				s.push(res);
			} else {
				s.push(atof(input[i].c_str()));
			}
		}
		std::cout << s.top() << std::endl;
	}
}
