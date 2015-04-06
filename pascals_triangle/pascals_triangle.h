/*
 * pascals_triangle.h
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#ifndef PASCALS_TRIANGLE_PASCALS_TRIANGLE_H_
#define PASCALS_TRIANGLE_PASCALS_TRIANGLE_H_

#include <string>

class Pascal
{
private:
	int factorial(const int &n);
	int nchoosek(const int &n, const int &k);

public:
	Pascal(const char *file);
};


#endif /* PASCALS_TRIANGLE_PASCALS_TRIANGLE_H_ */
