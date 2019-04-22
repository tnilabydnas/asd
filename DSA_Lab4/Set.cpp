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
	
}

bool Set::remove(TElem e)
{

}

bool Set::search(TElem e) const
{

}

int Set::size() const
{

}

bool Set::isEmpty() const
{

}

TElem Set::get(int p) const
{
	
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