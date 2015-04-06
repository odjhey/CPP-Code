/*
 * gold.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "gold.h"

Gold::Gold(const char *file)
{
	std::ifstream stream(file);
	std::string line;

	getline(stream, line);
	std::vector<std::string> info = split(line, ' ');
	int WIDTH = atoi(info[0].c_str());
	int HEIGHT= atoi(info[1].c_str());

	std::vector<std::vector<char> > grid(WIDTH, std::vector<char>(HEIGHT));
	std::vector<std::vector<bool> > visited(WIDTH, std::vector<bool>(HEIGHT));

	std::pair<int, int> startPos;

	for(int y = 0; y < HEIGHT; y++)
	{
		getline(stream, line);
		for(int x = 0; x < WIDTH; x++)
		{
			grid[x][y] = line[x];
			if(line[x] == 'P')
			{
				startPos.first = x;
				startPos.second = y;
			}
		}
	}

	gold = 0;
	dfs(grid, visited, startPos.first, startPos.second);
	std::cout << gold << std::endl;
}

std::vector<std::string> Gold::split(const std::string &text, char delim) const
{
	std::vector<std::string> vec;
	std::stringstream ss(text);
	std::string temp;
	while(getline(ss, temp, delim))
	{
		vec.push_back(temp);
	}
	return vec;
}

void Gold::dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited, int x, int y)
{
	if(grid[x][y] == 'P' || grid[x][y] == 'G' || grid[x][y] == '.')
	{
		visited[x][y] = true;

		if(grid[x][y] == 'G')
		{
			gold++;
		}

		if(grid[x+1][y] == 'T' || grid[x-1][y] == 'T' || grid[x][y+1] == 'T' || grid[x][y-1] == 'T')
			return;

		if(!visited[x+1][y])
			dfs(grid, visited, x+1, y);
		if(!visited[x-1][y])
			dfs(grid, visited, x-1, y);
		if(!visited[x][y+1])
			dfs(grid, visited, x, y+1);
		if(!visited[x][y-1])
			dfs(grid, visited, x, y-1);
	}
}

