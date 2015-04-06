/*
 * sheep.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Koe
 */

#include "sheep.h"
#include <iostream>
#include<fstream>
#include <sstream>

std::vector<std::string> Sheep::split(const std::string &text, char delim) const
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

void Sheep::dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited)
{
	cc = 0;
	for(int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[i].size(); j++)
		{
			if(grid[i][j] != '.' && !visited[i][j])
			{
					dfs(grid, visited, i, j);
					cc++;
			}
		}

	}
}

void Sheep::dfs(const std::vector<std::vector<char> > &grid, std::vector<std::vector<bool> > &visited, int x, int y) const
{
	if(grid[x][y] == '#')
	{
		visited[x][y] = true;

		if(x-1 >= 0 && !visited[x-1][y])
		{
			dfs(grid, visited, x-1, y);
		}
		if(x+1 < grid.size() && !visited[x+1][y])
		{
			dfs(grid, visited, x+1, y);
		}
		if(y-1 >= 0 && !visited[x][y-1])
		{
			dfs(grid, visited, x, y-1);
		}
		if(y+1 < grid[x].size() && !visited[x][y+1])
		{
			dfs(grid, visited, x, y+1);
		}
	}
}

Sheep::Sheep(const char *file)
{
	std::ifstream stream(file);
	std::string line;
	getline(stream, line);
	int N = atoi(line.c_str());

	for(int i = 0; i < N; i++)
	{
		getline(stream, line);

		std::vector<std::string> info = split(line, ' ');
		int WIDTH = atoi(info[0].c_str());
		int HEIGHT = atoi(info[1].c_str());

		std::vector<std::vector<char> > grid(WIDTH,std::vector<char>(HEIGHT));
		std::vector<std::vector<bool> > visited(WIDTH,std::vector<bool>(HEIGHT));

		for(int x = 0; x < WIDTH; x++)
		{
			getline(stream, line);
			for(int y = 0; y < HEIGHT; y++)
			{
				grid[x][y] = line[y];
			}
		}

		dfs(grid, visited);
		std::cout << cc << std::endl;
	}
}
