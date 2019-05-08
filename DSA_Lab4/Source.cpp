#include <iostream>
#include <assert.h>
using namespace std;
#include "Set.h"
#include "ExtendedTest.h"

int main()
{
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0);
	assert(s.add(5) == true);
	assert(s.add(1) == true);
	assert(s.add(10) == true);
	assert(s.add(7) == true);
	assert(s.add(1) == false);
	assert(s.add(10) == false);
	assert(s.add(-3) == true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		//cout << e << " ";
		it.next();
	}
	assert(sum == 19);

	testAllExtended();
	
	//cout << endl << s.getRange() <<endl;

	system("pause");
	return 0;
}