/*
 * splitthenumber.h
 *
 *  Created on: Apr 11, 2015
 *      Author: Koe
 */

#ifndef SPLIT_THE_NUMBER_SPLITTHENUMBER_H_
#define SPLIT_THE_NUMBER_SPLITTHENUMBER_H_

#include <string>
#include <vector>

class split_the_number {
	std::vector<std::string> split(const std::string &text, const char delim);
public:
	split_the_number(const char *file);
};

#endif /* SPLIT_THE_NUMBER_SPLITTHENUMBER_H_ */
