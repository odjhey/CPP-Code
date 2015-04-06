/*
 * stringrotation.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#include "stringrotation.h"

#include <iostream>
#include <fstream>
#include <sstream>

StringRotation::StringRotation(const char *file)
{
	std::ifstream stream(file);
	std::string line;

	while(getline(stream, line))
	{
		std::vector<std::string> info = split(line, ',');
		if(info[0].size() != info[1].size())
		{
			std::cout << "False" << std::endl;
		}
		else
		{
			if((info[0] + info[0]).find(info[1]) != std::string::npos)
			{
				std::cout << "True" << std::endl;
			}
			else
			{
				std::cout << "False" << std::endl;
			}
		}
	}
}

std::vector<std::string> StringRotation::split(const std::string &text, char delim)
{
	std::vector<std::string> vec;
	std::stringstream ss(text);
	std::string temp;
	while(getline(ss, temp, delim))
	{
		vec.push_back(temp);
	}
	return vec;
}
