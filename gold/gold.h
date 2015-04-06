/*
 * gold.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#ifndef GOLD_GOLD_H_
#define GOLD_GOLD_H_

#include <vector>
#include <string>

class Gold {
private:
	int gold;
private:
	std::vector<std::string> split(const std::string &text, char delim) const;
	void dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited, int x, int y);
public:
	Gold(const char *file);
};

#endif /* GOLD_GOLD_H_ */
