// Components for manipulating Trie Tree, or prefix tree

// Copyright (C) 2012, zhongchao.ustc@gmail.com
//
// This file is part of the WebYY C++ Meida Proxy.

#include "Trie.h"
#include "Logger.h"

Trie::Trie(TrieNode::Encoding encoding) : __emptyRoot(TrieNode(encoding)), __size(0) {
	switch (encoding) {
	case TrieNode::UTF8:
		__pace = 1;
		break;
	case TrieNode::UTF16:
		__pace = 2;
		break;
	default:
		Logger::error("Unrecognized encoding type.");
		break;
	}
}

TrieNode*
Trie::insert(std::string& keyword) {
	return insert(&__emptyRoot, keyword);
}

TrieNode*
Trie::insert(const char* keyword) {
	std::string ___keyword(keyword);
	return insert(___keyword);
}

TrieNode*
Trie::insert(TrieNode* parent, std::string& keyword) {
	if (keyword.size() == 0) {
		return NULL;
	}
	std::string ___firstCharacter = keyword.substr(0, __pace);
	TrieNode* ___firstNode = parent->findChild(___firstCharacter);
	if (___firstNode == NULL) {
		return insertBranch(parent, keyword);
	}
	std::string ___restString = keyword.substr(__pace, keyword.size());
	return insert(___firstNode, ___restString);
}

TrieNode*
Trie::insertBranch(TrieNode* parent, std::string& keyword) {
	std::string ___firstCharacter = keyword.substr(0, __pace);
	TrieNode* ___firstNode = parent->insertChild(___firstCharacter);
	if (___firstNode != NULL) {
		std::string ___restString = keyword.substr(__pace, keyword.size());
		if (!___restString.empty())
			return insertBranch(___firstNode, ___restString);
	}
	return NULL;
}

TrieNode*
Trie::find(std::string& keyword) {
	return find(&__emptyRoot, keyword);
}

TrieNode*
Trie::find(TrieNode* parent, std::string& keyword) {
	std::string ___firstChild = keyword.substr(0, __pace);
	TrieNode* ___firstNode = parent->findChild(___firstChild);
	if (___firstNode == NULL) {
		return NULL;
	}

	// Last character, then stop searching
	if (keyword.size() == __pace) {
		return ___firstNode;
	}

	// More than one character
	std::string ___restString = keyword.substr(__pace, keyword.size());
	if (___firstNode->__map.empty()) {
		return ___firstNode; // CASE: "fuck" in "fucking"
	}
	return find(___firstNode, ___restString);
}

std::string
Trie::toString() {
	std::string ___result("[");
	bool ___isFirstChild = true;
	for (TrieNode::_TrieMapIterator ___it = __emptyRoot.__map.begin();
			___it != __emptyRoot.__map.end(); ++___it) {
		if (___isFirstChild) {
			___result.append(toString(const_cast<TrieNode*>(&(___it->second))));
			___isFirstChild = false;
		} else {
			___result.append(",");
			___result.append(toString(const_cast<TrieNode*>(&(___it->second))));
		}
	}
	___result.append("]");
	return ___result;
}

std::string
Trie::toString(TrieNode* parent) {

	std::string ___result("[");
	___result += parent->getCharacter() + ":";

	bool ___isFirstChild = true;
	for (TrieNode::_TrieMapIterator ___it = parent->__map.begin();
				___it != parent->__map.end(); ++___it) {
		if (___isFirstChild) {
			___result.append(toString(const_cast<TrieNode*>(&(___it->second))));
			___isFirstChild = false;
		} else {
			___result.append(",");
			___result.append(toString(const_cast<TrieNode*>(&(___it->second))));
		}
	}
	___result.append("]");
	return ___result;
}

std::string
Trie::getKeywords() {
	std::string ___result;
	for (TrieNode::_TrieMapIterator ___it = __emptyRoot.__map.begin();
			___it != __emptyRoot.__map.end(); ++___it) {
		___result.append(getKeywords(___it->first, &(___it->second)));
	}
	return ___result;
}

std::string
Trie::getKeywords(const std::string& character, const TrieNode* parent) {
	std::string ___result;
	for (TrieNode::_TrieMapIterator ___it = parent->__map.begin();
			___it != parent->__map.end(); ++___it) {
//		std::string ___tempChar;
//		___tempChar.assign(character);
		___result.append(Logger::toHex(character, true));
		___result.append(getKeywords(___it->first, &(___it->second)));
	}

	// Last character
	if (parent->__map.size() == 0) {
//		std::string ___tempChar;
//		___tempChar.assign(character);
		__size++;
		___result.append(Logger::toHex(character, true));
		___result.append("\n");
	}
	return ___result;
}
