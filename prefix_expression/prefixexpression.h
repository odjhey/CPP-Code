/*
 * prefixexpression.h
 *
 *  Created on: Apr 14, 2015
 *      Author: Koe
 */

#ifndef PREFIX_EXPRESSION_PREFIXEXPRESSION_H_
#define PREFIX_EXPRESSION_PREFIXEXPRESSION_H_

#include <string>
#include <vector>

class prefix_expression {
private:
	std::vector<std::string> split(const std::string &text, const char delim);
public:
	prefix_expression(const char *file);
};

#endif /* PREFIX_EXPRESSION_PREFIXEXPRESSION_H_ */
