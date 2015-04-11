/*
 * zeroes.h
 *
 *  Created on: Apr 11, 2015
 *      Author: Koe
 */

#ifndef JUGGLING_WITH_ZEROS_ZEROES_H_
#define JUGGLING_WITH_ZEROS_ZEROES_H_

#include <vector>
#include <string>

class Zeroes {
private:
	std::vector<std::string> split(const std::string &text, const char delim);
public:
	Zeroes(const char *file);
};

#endif /* JUGGLING_WITH_ZEROS_ZEROES_H_ */
