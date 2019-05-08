#include "Set.h"
#include <limits>

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

//TH(1)
bool Set::add(TElem e)
{
	if (this->search(e))
		return false;

	if (this->head == -1)
	{
		this->head = this->firstEmpty;
		this->firstEmpty = this->next[this->head];
		this->elems[this->head] = e;
		++this->length;
		return true;
	}
	if (this->firstEmpty < 0 || this->firstEmpty >= cap)
		return false;

	this->elems[this->firstEmpty] = e;
	this->firstEmpty = this->next[this->firstEmpty];
	++this->length;
	return true;
}

//TH(n)
bool Set::remove(TElem e)
{
	int i = this->head, j = 0;
	if (this->elems[this->head] == e)
	{
		this->head = this->next[this->head];
		--this->length;
		return true;
	}
	while (j < this->length)
	{
		if (this->elems[next[i]] == e)
		{
			this->next[i] = this->next[this->next[i]];
			this->prev[this->next[i]] = i;
			--this->length;
			return true;
		}
		++j;
		i = this->next[i];
	}
	return false;
}

//O(n)
int Set::getRange() const
{
	if (this->length == 0)
		return -1;

	TElem Min = INT_MAX;
	TElem Max = INT_MIN;

	int i = this->head;
	int j = 0;
	while (j < this->length)
	{
		if (this->elems[i] < Min)
			Min = this->elems[i];
		if (this->elems[i] > Max)
			Max = this->elems[i];
		i = this->next[i];
		++j;
	}
	return Max - Min;
}

//TH(n)
bool Set::search(TElem e) const
{
	int i = this->head,j=0;
	while (j < this->length)
	{
		if (this->elems[i] == e)
			return true;
		++j;
		i = next[i];
	}
	return false;
}

//TH(1)
int Set::size() const
{
	return this->length;
}

//TH(1)
bool Set::isEmpty() const
{
	return this->size() == 0;
}

//O(n)
TElem Set::get(int p) const
{
	if (p > this->length)
		return -1;
	int j = 0, i = this->head;
	while (j < p)
	{
		++j;
		i = this->next[i];
	}
	return this->elems[i];
}

//TH(1)
SetIterator Set::iterator() const
{
	return SetIterator(*this);
}

Set::~Set()
{
	delete this->elems;
	delete this->next;
	delete this->prev;
}
