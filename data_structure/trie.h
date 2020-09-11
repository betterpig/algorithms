#pragma once
#include "common.h"

struct TrieNode
{
	bool is_end;
	vector<TrieNode*> next;
	TrieNode() :is_end(false),next(26,nullptr){}
};

class Trie
{
private:
	TrieNode* root;
public:
	Trie() :root(new TrieNode) {}
	TrieNode* GetRoot() { return root; }
	bool find(string word);
	void insert(string word);
	TrieNode* destruct(TrieNode* root);
};

bool Trie::find(string word)
{
	TrieNode* p = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (p->next[word[i] - 'a'] == nullptr)
			return false;
		p = p->next[word[i] - 'a'];
	}
	return p->is_end;
}

void Trie::insert(string word)
{
	TrieNode* p = root;
	for (int i = 0; i < word.size(); i++)
	{
		if (p->next[word[i] - 'a'] == nullptr)
			p->next[word[i] - 'a'] = new TrieNode();
		p = p->next[word[i] - 'a'];
	}
	p->is_end = true;
}

TrieNode* Trie::destruct(TrieNode* root)
{
	for (int i = 0; i < 26; i++)
	{
		if (root->next[i])
			root->next[i]=destruct(root->next[i]);
	}
	delete root;
	return nullptr;
}
