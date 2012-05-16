// Components for manipulating Trie Tree, or prefix tree

// Copyright (C) 2012, zhongchao.ustc@gmail.com
//
// This file is part of the WebYY C++ Meida Proxy.

#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include "TrieNode.h"

class Trie {
private:

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief The root of this whole Trie, which member variable __character is
	 * not used for storing a character. __emtryRoot is only considered as the
	 * entry of the Trie.
	 */
	TrieNode __emptyRoot;

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief The data length for each node.
	 */
	int __pace;

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Insert the keyword, which maybe is a partial string of the origin
	 * source keyword, into this Trie. Starting point node of searching is the
	 * childs map of parent.
	 */
	TrieNode* insert(TrieNode* parent, std::string& keyword);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Insert the characters of the keyword directly into the Trie as a
	 * branch of some leaf and any node of this branch only has one child.
	 */
	TrieNode* insertBranch(TrieNode* parent, std::string& keyword);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Find the keyword, which maybe is a partial string of the origin
	 * source keyword, into this Trie. Starting point node of searching is the
	 * childs map of parent.
	 */
	TrieNode* find(TrieNode* parent, std::string& keyword);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Get a string standing for the Trie.
	 */
	std::string toString(TrieNode* parent);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Show all keywords.
	 */
	std::string getKeywords(const std::string& character, const TrieNode* parent);

public:

	int __size;

	Trie(TrieNode::Encoding encoding);
	~Trie();

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Insert the keyword into the Trie. If the keyword has been
	 * contained in the Trie, nothing will be done. If any error occurs, return
	 * NULL pointer.
	 */
	TrieNode* insert(std::string& keyword);
	TrieNode* insert(const char* keyword);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Find if the argument keyword is contained in this Trie, using
	 * recursively searching. If the keyword was found, a pointer to the
	 * TrieNode which has the keyword as its value will be returned. If it is
	 * not contained or any unknown error occurs, then return NULL pointer.
	 */
	TrieNode* find(std::string& keyword);

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Get a string standing for the Trie.
	 */
	std::string toString();

	/*
	 * @author zhongchao.ustc@gmail.com
	 * @brief Show all keywords.
	 */
	std::string getKeywords();
};

inline Trie::~Trie() {
}

#endif /* TRIE_H */
