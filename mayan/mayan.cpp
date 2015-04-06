/*
 * mayan.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#include "mayan.h"
#include <iostream>
#include <fstream>
#include <sstream>

Mayan::Mayan(const char *file)
{

	std::ifstream stream(file);
	std::string line;

	getline(stream, line);
	std::vector<std::string> info = split(line,' ');
	int g = atoi(info[0].c_str());
	int S = atoi(info[1].c_str());

	std::vector<int> glyphs('z' + 1);
	std::vector<int> carvings('z' + 1);

	std::string strGlyphs;
	getline(stream, strGlyphs);
	for(int i = 0; i < g; i++)
		glyphs[strGlyphs[i]]++;

	std::string strCarvings;
	getline(stream, strCarvings);
	for(int i = 0; i < g; i++)
		carvings[strCarvings[i]]++;

	int totalAppearances = 0;
	if(checkGlyph(glyphs, carvings, strGlyphs))
		totalAppearances++;

	for (int i = 1; i < strCarvings.size() - g + 1; i++)
	{
		carvings[strCarvings[i-1]]--;
		carvings[strCarvings[i + g - 1]]++;
		if (checkGlyph(glyphs, carvings, strGlyphs)) {
			totalAppearances++;
		}
	}

	std::cout << totalAppearances << std::endl;
}

bool Mayan::checkGlyph(const std::vector<int> &glyphs, const std::vector<int> &carvings,
		const std::string &strGlyphs)
{
	for (int i = 0; i < strGlyphs.size(); i++) {
		if (glyphs[strGlyphs[i]] != carvings[strGlyphs[i]]) {
			return false;
		}
	}
	return true;
}

std::vector<std::string> Mayan::split(const std::string &text, char delim)
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
