/*
 * mayan.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#ifndef MAYAN_MAYAN_H_
#define MAYAN_MAYAN_H_

#include <vector>
#include <string>

class Mayan {
private:
	std::vector<std::string> split(const std::string &text, char delim);
	bool checkGlyph(const std::vector<int> &glyphs, const std::vector<int> &carvings,
			const std::string &strGlyphs);

public:
	Mayan(const char *file);
};

#endif /* MAYAN_MAYAN_H_ */
