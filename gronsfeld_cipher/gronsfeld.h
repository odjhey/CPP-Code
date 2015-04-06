/*
 * gronsfeld.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#ifndef GRONSFELD_CIPHER_GRONSFELD_H_
#define GRONSFELD_CIPHER_GRONSFELD_H_

#include <string>
#include <vector>

class Gronsfeld {
private:
	void decrypt(std::string &cipher, const std::string &key, const std::string &alphabet);
	std::vector<std::string> split(const std::string &text, char delim);
public:
	Gronsfeld(const char *file);
};

#endif /* GRONSFELD_CIPHER_GRONSFELD_H_ */
