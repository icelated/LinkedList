#ifndef _LIST_
#define _LIST_

#include <ostream>
#include "winery.h"

using namespace std;

class list
{
public:
	list(void);				// constructor
	virtual ~list(void);	// destructor
	void displayByName(ostream& out) const;
	void displayByRating(ostream& out) const;
	void insert(const winery& winery);
	winery * const find(const char * const name) const;
	bool remove(const char * const name);

private:
	struct node
	{
		node(const winery& winery);		// constructor
		winery item;
		node * nextByName;
		node * nextByRating;
	};

	node * headByName;
	node * headByRating;
};

#endif // _LIST_
