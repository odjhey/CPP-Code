/*
 * main.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */



#include <iostream>

#if 1
#define PASCAL
#include "pascals_triangle/pascals_triangle.h"
#endif

#if 1
#define OUTLET
#include "outlet/outlet.h"
#endif

#if 1
#define SHEEP
#include "sheep/sheep.h"
#endif

#if 1
#define GOLD
#include "gold/gold.h"
#endif

#if 1
#define MAYAN
#include "mayan/mayan.h"
#endif

int main(int argc, char *argv[])
{

#ifdef PASCAL
	std::cout << "Pascals Triangle:" << std::endl;
	Pascal p("pascals_triangle/test.txt");
	std::cout << std::endl;
#endif

#ifdef OUTLET
	std::cout << "Outlet:" << std::endl;
	Outlet o("outlet/test.txt");
	std::cout << std::endl;
#endif

#ifdef SHEEP
	std::cout << "Sheep:" << std::endl;
	Sheep s("sheep/test.txt");
	std::cout << std::endl;
#endif

#ifdef GOLD
	std::cout << "Gold:" << std::endl;
	Gold g("gold/test.txt");
	std::cout << std::endl;
#endif

#ifdef MAYAN
	std::cout << "Mayan:" << std::endl;
	Mayan m("mayan/test.txt");
	std::cout << std::endl;
#endif

	return 0;
}
