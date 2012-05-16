// Components for manipulating Trie Tree, or prefix tree

// Copyright (C) 2012, zhongchao.ustc@gmail.com
//
// This file is part of the WebYY C++ Meida Proxy.

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include "Logger.h"
#include <string>
#include <map>

class Trie;

class TrieNode {

	friend class Trie;
	typedef std::map<std::string, TrieNode> _TrieMap;
	typedef std::map<std::string, TrieNode>::const_iterator _TrieMapIterator;

private:
	std::string __character;
	_TrieMap	__map;
	TrieNode*	__parent;
	int			__dataSize;

public:

	enum Encoding {
		UTF8	= 1,
		UTF16	= 2
	};

	TrieNode(int dataSize);
	TrieNode(std::string character, int dataSize);
	~TrieNode();

	// Used in Trie
	std::string getCharacter() const;
	TrieNode* findChild(std::string& nextCharacter) const;
	TrieNode* insertChild(std::string& nextCharacter);

};

inline TrieNode::TrieNode(int dataSize) {
	__dataSize = dataSize;
}

inline TrieNode::~TrieNode() {
}

inline std::string TrieNode::getCharacter() const {
	return __character;
}
#endif /* TRIE_NODE_H */
