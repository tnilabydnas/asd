#pragma once
#include "Set.h"

class Set;

class SetIterator
{
	friend class Set;

private:
	const Set& con;
	int current;
	SetIterator(const Set&);

public:
	TElem getCurrent();
	bool valid();
	void next();
	void first();
};

