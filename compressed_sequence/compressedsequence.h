/*
 * compressedsequence.h
 *
 *  Created on: Apr 7, 2015
 *      Author: Koe
 */

#ifndef COMPRESSED_SEQUENCE_COMPRESSEDSEQUENCE_H_
#define COMPRESSED_SEQUENCE_COMPRESSEDSEQUENCE_H_

#include <vector>
#include <string>

class cmpSequence {
private:
	std::vector<std::string> split(const std::string &text, char delim);
	template<class T> std::vector<T> _split(const std::string &text, char delim);
public:
	cmpSequence(const char *file);
};

#endif /* COMPRESSED_SEQUENCE_COMPRESSEDSEQUENCE_H_ */
