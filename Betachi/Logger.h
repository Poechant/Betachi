/*
 * Logger.h
 *
 *  Created on: 2012-5-15
 *      Author: michael
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>

class Logger {
private:
	static void print(std::string msg) { std::cout << msg << std::endl; }
	static void print(const char* msg) { std::cout << msg << std::endl; }
public:
	static void error(std::string msg) { print(msg); }
	static void error(const char* msg) { print(msg); }
	static void debug(std::string msg) { print(msg); }
	static void debug(const char* msg) { print(msg); }
	static void info(std::string msg) { print(msg); }
	static void info(const char* msg) { print(msg); }
	static std::string toHex(const std::string& msg, bool upperCase);
};

#endif /* LOGGER_H_ */
