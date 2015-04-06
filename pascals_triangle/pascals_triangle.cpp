/*
 * pascals_triangle.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#include "pascals_triangle.h"
#include <iostream>
#include <fstream>

Pascal::Pascal(const char *file)
{
	std::ifstream stream(file);
	std::string line;
	while(getline(stream,line))
	{
		int n = atoi(line.c_str());
		for(int i = 0; i < n; i++)
		{
			for(int k = 0; k <= i; k++)
			{
				std::cout << nchoosek(i,k) << " ";
			}
		}
		std::cout << std::endl;
	}
}

int Pascal::nchoosek(const int &n, const int &k)
{
	return factorial(n) / (factorial(k) * factorial(n-k));
}

int Pascal::factorial(const int &n)
{
	if (n <= 1)
		return 1;
	return n * factorial(n-1);
}
