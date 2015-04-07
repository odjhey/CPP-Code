/*
 * burrowswheeler.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Koe
 */

#include "burrowswheeler.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

BurrowsWheeler::BurrowsWheeler(const char *file)
{
	std::ifstream stream(file);
	std::string line;

	while(getline(stream, line))
	{
		std::cout << unpack(line.substr(0,line.size()-1), '$') << std::endl;
	}
}

std::vector<std::string> BurrowsWheeler::make_rotations(const std::string &text)
{
	std::vector<std::string> vec;
	std::string temp = text + text;
	std::size_t text_size = text.size();

	for(std::size_t i = 0; i < temp.size() - text_size; ++i)
	{
		vec.push_back(temp.substr(i, text_size));
	}
	return vec;
}

std::string BurrowsWheeler::get_bwt(const std::vector<std::string> &vec)
{
	std::string bwt;
	std::size_t text_size = vec[0].size();
	for(std::size_t i = 0; i != vec.size(); ++i)
	{
		bwt += vec[i][text_size-1];
	}
	return bwt;
}

std::string BurrowsWheeler::pack(const std::string &text)
{
	std::vector<std::string> rotations = make_rotations(text);
	std::sort(rotations.begin(), rotations.end());
	return get_bwt(rotations);
}

// Works, but slooooooow
std::string BurrowsWheeler::unpack(const std::string &bwt, const char char_EOF)
{
	std::size_t decrypted_pos = bwt.find(char_EOF);

	std::size_t bwt_len = bwt.size();
	std::vector<std::string> vec(bwt_len);

	for(std::size_t i = 0; i < bwt_len; ++i)
	{
		for(std::size_t j = 0; j < bwt_len; ++j)
		{
			vec[j] = bwt[j] + vec[j];
		}
		std::sort(vec.begin(), vec.end());
	}

	return vec[decrypted_pos];
}
