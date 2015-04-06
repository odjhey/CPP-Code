/*
 * outlet.h
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#ifndef OUTLET_OUTLET_H_
#define OUTLET_OUTLET_H_

#include <vector>
#include <string>

class Outlet {
private:
	std::vector<std::string> split(const std::string &text, char delim);
public:
	Outlet(const char *file);
};

#endif /* OUTLET_OUTLET_H_ */
