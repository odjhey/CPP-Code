/*
 * outlet.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#include "outlet.h"
#include <iostream>
#include <sstream>
#include <fstream>

Outlet::Outlet(const char *file)
{
	std::ifstream stream(file);
	std::string line;
	getline(stream, line);
	int N = atoi(line.c_str());

	for(int i = 0; i < N; i++)
	{
		getline(stream, line);
		int num_strips = atoi(line.c_str());
		getline(stream, line);
		std::vector<std::string> nums = split(line, ' ');

		int sum = 0;
		for(int j = 0; j < nums.size(); j++)
		{
			int temp = atoi((nums[j]).c_str());
			if(j < nums.size() - 1)
				temp--;
			sum += temp;
		}
		std::cout << sum << std::endl;
	}
}

std::vector<std::string> Outlet::split(const std::string &text, char delim)
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
