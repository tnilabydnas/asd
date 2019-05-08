#pragma once

#include "SetIterator.h"

typedef int TElem;

const int cap = 100000;

class SetIterator;

class Set
{
	friend class SetIterator;
	
private:
	int *elems, *next, *prev;
	int head, firstEmpty, length;

public:
	Set();
	bool add(TElem);
	bool remove(TElem);
	bool search(TElem) const;
	TElem get(int) const;
	int size() const;
	bool isEmpty() const;
	SetIterator iterator() const;
	int getRange() const;
	~Set();
};