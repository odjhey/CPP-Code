/*
 * burrowswheeler.h
 *
 *  Created on: Apr 7, 2015
 *      Author: Koe
 */

#ifndef BURROWS_WHEELER_BURROWSWHEELER_H_
#define BURROWS_WHEELER_BURROWSWHEELER_H_

#include <string>
#include <vector>

class BurrowsWheeler {
private:
	std::vector<std::string> make_rotations(const std::string &text);
	std::string get_bwt(const std::vector<std::string> &vec);
public:
	BurrowsWheeler(const char *file);
	std::string pack(const std::string &text);
	std::string unpack(const std::string &bwt, const char char_EOF);
};

#endif /* BURROWS_WHEELER_BURROWSWHEELER_H_ */
