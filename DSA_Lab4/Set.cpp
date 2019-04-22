#include "Set.h"

Set::Set()
{
	this->elems = new TElem[cap];
	this->next = new int[cap];
	this->prev = new int[cap];
	this->head = -1;
	for (int i = 0; i < cap; ++i)
	{
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	this->firstEmpty = 0;
}

bool Set::add(TElem e)
{
	this->elems[this->firstEmpty] = e;
	return true;
}

bool Set::remove(TElem e)
{
	return false;
}

bool Set::search(TElem e) const
{
	return true;
}

int Set::size() const
{
	return this->length;
}

bool Set::isEmpty() const
{
	return true;
}

TElem Set::get(int p) const
{
	return 0;
}

SetIterator Set::iterator() const
{
	return SetIterator(*this);
}

Set::~Set()
{
	delete this->elems;
	delete this->next;
}
