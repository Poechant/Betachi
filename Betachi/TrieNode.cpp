// Components for manipulating Trie Tree, or prefix tree

// Copyright (C) 2012, zhongchao.ustc@gmail.com
//
// This file is part of the WebYY C++ Meida Proxy.

#include "TrieNode.h"

TrieNode::TrieNode(std::string character, int dataSize) {
	if (character.size() == 2)
		__character.assign(character);
	else Logger::error("error");
}

TrieNode*
TrieNode::findChild(std::string& nextCharacter) const {
	_TrieMapIterator ___trieMapIt = __map.find(nextCharacter);
	return (___trieMapIt == __map.end()) ? NULL : const_cast<TrieNode*>(&(___trieMapIt->second));
}

TrieNode*
TrieNode::insertChild(std::string& nextCharacter) {
	if (!findChild(nextCharacter)) {
		__map.insert(std::pair<std::string, TrieNode>(nextCharacter, TrieNode(nextCharacter, __dataSize)));
		return &(__map.find(nextCharacter)->second);
	}
	return NULL;
}
