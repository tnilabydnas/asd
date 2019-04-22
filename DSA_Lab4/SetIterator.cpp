#include "SetIterator.h"
#include "Set.h"

SetIterator::SetIterator(const Set& c) : con(c)
{
	this->current = 0;
}

TElem SetIterator::getCurrent()
{
	return this->con.get(this->current);
}

bool SetIterator::valid()
{
	return this->con.size() > this->current;
}

void SetIterator::next()
{
	++this->current;
}

void SetIterator::first()
{
	this->current = 0;
}