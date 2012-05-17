/*
 * main.cpp
 *
 *  Created on: 2012-5-9
 *      Author: michael
 */

#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Filter.h"
#include <sys/time.h>
#include "Trie.h"
#include "Logger.h"

typedef struct timeval Time;

double g_totalSeconds = 0;

Time getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv;
}

double timeInterval(Time& tv1, Time& tv2) {
	return (tv2.tv_sec - tv1.tv_sec) * 1.0
			+ (tv2.tv_usec - tv1.tv_usec) * 1.0 / 1000000;
}

void testCensor(const char* source, int length, bool (*testFun)(const char*, int)) {
	if (!Filter::isInitialized()) {
		Filter::init(Filter::HIGH);
	}
	Time startTime = getCurrentTime();
	std::cout << "-- start --------------------------------------" << std::endl;
	std::cout << (testFun(source, length) ? "legal" : "illegal") << std::endl;
	Time endTime = getCurrentTime();
	g_totalSeconds += timeInterval(startTime, endTime);
	std::cout << "time costs: " << g_totalSeconds << " seconds" << std::endl;
	std::cout << "--- end -------------------------------------" << std::endl;
}

int main() {

	std::vector<std::string> msgs;;
	msgs.push_back("\x5D\x78\x78\x91\x18\x75\xB9\x6C\xB8\x70\x39\x5F\x36\x52\x5C\x4F");
	msgs.push_back("\x54\x00\x4E\x00\x54\x00\x20\x00\xB8\x70\x39\x5F\x84\x76\x36\x52\x5C\x4F");
	msgs.push_back("\x5D\x78\xF5\x94\xB8\x70\x6F\x83\x4D\x91\xB9\x65");
	msgs.push_back("\x5D\x78\x78\x91\x18\x75\xB9\x6C\x36\x52\x5C\x4F");
	msgs.push_back("\xB8\x70\x39\x5F\x4D\x91\xB9\x65");
	msgs.push_back("\x80\x7B\x13\x66\xB8\x70\x6F\x83");
	msgs.push_back("\x0D\x00"); //
	msgs.push_back("\x80\x7B\x13\x66\xB8\x70\x6F\x84"); //
	msgs.push_back("\x6B\x70\x6F\x83\x36\x52\x5C\x4F\x80\x7B\x13\x66\xB8\x70\x39\x5F");
	msgs.push_back("\xB8\x70\x39\x5F\x36\x52\x5C\x4F");
	msgs.push_back("\xB8\x70\x39\x5A"); //

	for (int i = 0; i < 10000; ++i) {
		for (std::vector<std::string>::iterator it = msgs.begin(); it != msgs.end(); ++it) {
			testCensor(it->data(), it->size(), Filter::censor);
		}
	}

	std::cout << "Total seconds: " << g_totalSeconds << std::endl;

	return 0;
}
