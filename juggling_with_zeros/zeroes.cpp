/*
 * zeroes.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: Koe
 */

#include "zeroes.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

Zeroes::Zeroes(const char *file)
{
	std::ifstream stream(file);
	std::string line;

	while(std::getline(stream, line))
	{
		std::vector<std::string> input = split(line, ' ');
		std::string binary = "";

		for(std::size_t i = 0; i < input.size()-1; i+=2)
		{
			std::string &flag = input[i];
			std::string &seq = input[i+1];


			if(flag.size() == 2) {
				for(std::size_t j = 0; j < seq.size(); ++j)
					binary += "1";
			} else if (flag.size() == 1) {
				for(std::size_t j = 0; j < seq.size(); ++j)
					binary += "0";

			}
		}

		unsigned int num = 0;
		std::size_t b_size = binary.size() - 1;
		for(int i = b_size; i >= 0; --i)
		{
			if(binary[i] == '1') {
				num += pow(2, b_size-i);
			}
		}
		std::cout << num << std::endl;
	}
}

std::vector<std::string> Zeroes::split(const std::string &text, const char delim)
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
