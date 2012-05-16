/*
 * Filter.h
 *
 *  Created on: 2012-5-9
 *      Author: michael
 */

#ifndef FILTER_H_
#define FILTER_H_

#include <string>
#include "Trie.h"

class Filter {

private:

	static bool __LEGAL;
	static bool __ILLEGAL;
	static bool __initialized;
	static Trie __trie;
	static void load(const char* fileName, int startPos);
	static bool censor(std::string& source);

public:
	enum Level{
		NORMAL = 1,
		HIGH = 2
	};
	static void init(Level level);
	static bool isInitialized();
	static bool censor(const char* source, int length);
};

inline bool Filter::isInitialized() {
	return __initialized;
}

#endif /* FILTER_H_ */
