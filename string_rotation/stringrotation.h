/*
 * stringrotation.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#ifndef STRING_ROTATION_STRINGROTATION_H_
#define STRING_ROTATION_STRINGROTATION_H_

#include <string>
#include <vector>

class StringRotation {
private:
	std::vector<std::string> split(const std::string &text, char delim);
public:
	StringRotation(const char *file);
};

#endif /* STRING_ROTATION_STRINGROTATION_H_ */
