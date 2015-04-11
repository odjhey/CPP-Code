/*
 * splitthenumber.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: Koe
 */

#include "splitthenumber.h"

#include <iostream>
#include <fstream>
#include <sstream>

split_the_number::split_the_number(const char *file)
{
	std::ifstream stream(file);
	std::string line;
	while(std::getline(stream, line))
	{
		std::vector<std::string> input = split(line, ' ');
		std::string &number = input[0];
		std::string &pattern = input[1];

		bool is_plus = true;
		std::size_t pos = pattern.find('+');

		if(pos == std::string::npos)
		{
			is_plus = false;
			pos = pattern.find('-');
		}

		std::string a_str = "";
		for(std::size_t i = 0; i < pos; ++i)
			a_str += number[i];

		std::string b_str;
		for(std::size_t j = pos; j < number.size(); ++j)
			b_str += number[j];

		int a = std::atoi(a_str.c_str());
		int b = std::atoi(b_str.c_str());

		if(is_plus)
			std::cout << (a+b) << std::endl;
		else
			std::cout << (a-b) << std::endl;
	}
}

std::vector<std::string> split_the_number::split(const std::string &text, const char delim)
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
