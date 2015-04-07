/*
 * compressedsequence.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Koe
 */

#include "compressedsequence.h"

#include <iostream>
#include <fstream>
#include <sstream>

cmpSequence::cmpSequence(const char *file)
{
	std::ifstream stream(file);
	std::string line;

	while(getline(stream, line))
	{
		std::vector<std::string> temp = split(line,' ');
		std::vector<int> nums;

		for(int i = 0; i < temp.size(); i++) {
			nums.push_back(atoi(temp[i].c_str()));
		}

		int cur;
		int multiplier;
		std::string output = "";

		for(std::size_t i = 0;i  < nums.size(); i++) {
			multiplier = 0;
		    cur = nums[i];

		    while(nums[i] == cur && i < nums.size()) {
		    	multiplier++;
		        i++;
		    }
		    i--;

		    output += std::to_string(multiplier) + " " + std::to_string(cur);
		    if(i < nums.size()-1)
		    	output += " ";
		}
		std::cout << output << std::endl;
	}
}

std::vector<std::string> cmpSequence::split(const std::string &text, char delim)
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
