/*
 * gronsfeld.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: Koe
 */

#include "gronsfeld.h"

#include <iostream>
#include <fstream>
#include <sstream>

Gronsfeld::Gronsfeld(const char *file)
{
	const std::string alphabet = " !\"#$%&'()*+,-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::ifstream stream(file);
	std::string line;

	while(getline(stream, line))
	{
		std::vector<std::string> input = split(line, ';');

		std::string &key = input[0];
		std::string &cipher = input[1];

		decrypt(cipher, key, alphabet);
		std::cout << cipher << std::endl;
	}
}

void Gronsfeld::decrypt(std::string &cipher, const std::string &key, const std::string &alphabet)
{
	int key_count = 0;
	for(int i = 0; i < cipher.size(); ++i)
	{
		if(key_count >= key.size())
			key_count = 0;

		int decrypted_pos = alphabet.find(cipher[i]) - key[key_count]%48;
		if(decrypted_pos < 0) {
			decrypted_pos += alphabet.size();
		}

		cipher[i] = alphabet[decrypted_pos];
		++key_count;
	}
}

std::vector<std::string> Gronsfeld::split(const std::string &text, char delim)
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
