/*
 * sheep.h
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#ifndef SHEEP_SHEEP_H_
#define SHEEP_SHEEP_H_

#include <vector>

class Sheep {
private:
	int cc;
private:
	std::vector<std::string> split(const std::string &text, char delim) const;
	void dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited);
	void dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited, int x, int y) const;
public:
	Sheep(const char *file);
};

#endif /* SHEEP_SHEEP_H_ */
