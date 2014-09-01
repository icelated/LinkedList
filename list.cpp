#include <iostream>
#include <iomanip>
// enable Visual C++ memory leak checking
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "list.h"



/**
* List: constructor to initialize list
* in: none
* out: none
* return: none
**/
list::list()
{

	headByName = NULL;
	headByRating = NULL;

	int acres = 0;
	int rating = 0;

}
/**
* List: destructor
* in: none
* out: none
* return: none
**/
list::~list()
{


	node * curr = headByName;
	while(headByName)
	{
		curr = headByName->nextByName;
		delete headByName;		
		headByName = curr;
	} 

	node * current = headByRating;
	while(headByRating)
	{
		current = headByRating->nextByRating;
		delete headByRating;		
		headByRating = current;
	} 


}

/**
* List: displaybyname
* in: ostream
* out: none
* return: none
**/
void list::displayByName(ostream& out) const
{
	winery *wineryPtr;
	wineryPtr->displayHeadings(out);

	node* curr  = headByName;
	

	while ( curr )
	{
	   
    out << left
        << setw(25) << curr->item.getName()     << ' '
        << setw(20) << curr->item.getLocation() << ' '
        << right
        << setw(4)  << curr->item.getAcres()    << ' '
        << setw(9)  << curr->item.getRating()   << '\n';
		

	curr = curr->nextByName;
	}

  


}
/**
* List: displayRating
* in: ostream
* out: none
* return: none
**/
void list::displayByRating(ostream& out) const
{


	node *curr  = headByRating;
   winery *wineryPtr;
   wineryPtr->displayHeadings(out);

	while ( curr )
	{
	out << left
        << setw(25) << curr->item.getName()     << ' '
        << setw(20) << curr->item.getLocation() << ' '
        << right
        << setw(4)  << curr->item.getAcres()    << ' '
        << setw(9)  << curr->item.getRating()   << '\n';

		curr = curr->nextByRating;
	}
	
	
	
}

/**
* List: insert
* in: winery
* out: none
* return: none
**/

void list::insert(const winery& winery)
{



	node* wineryNode = new node(winery);    // winerynode for adding and sorting name
	node* prev = NULL;
	node* check = headByName;

	node* wineryRatingNode = new node(winery);   // winerynode for adding and sorting Rating
	node* prevRating = NULL;
	node* checkRating = headByRating;


	if ( headByName == NULL ) 
	{       
		headByName   = wineryNode;  
	}

	if ( headByRating == NULL)
	{
		headByRating = wineryRatingNode; 
	}


	while (check != NULL && (strcmp(check->item.getName(), wineryNode->item.getName() ) < 0))
	{

		prev = check;
		check = check->nextByName;
	}

	if (prev == NULL)
	{
		headByName = wineryNode;
	}
	else
	{
		prev->nextByName = wineryNode;
	}
	wineryNode->nextByName = check;  

    

	while (checkRating != NULL && (checkRating->item.getRating() > wineryRatingNode->item.getRating()))

	{
		prevRating = checkRating;
		checkRating = checkRating->nextByRating;
	}

	/// Sort for Rating *******************
	if (prevRating == NULL)
	{
		headByRating = wineryRatingNode;
	}
	else
	{
		prevRating->nextByRating = wineryRatingNode;
	}

	wineryRatingNode->nextByRating = checkRating;


   wineryNode  = NULL;
   delete [] wineryNode ;

   wineryRatingNode = NULL;
   delete  wineryRatingNode;
  
}

/**
* winery: find
* in: name
* out: none
* return: winery
**/
winery * const list::find(const char * const name) const
{

	node * curr;
	winery	*wPtr = NULL;
	winery *wineryPtr;
  	

	for(curr=headByName; curr; curr=curr->nextByName)
	{
		if(strcmp(curr->item.getName(), name) == 0)
		{

			wPtr = &curr->item; // address of curr->item
		   wineryPtr->displayHeadings(cout);

			return wPtr;         
		}

	}

	
	return 0;




}
/**
* List: remove
* in: name
* out: none
* return: true / false
**/
bool list::remove (const char * const name)
{

	//search for the data to be removed
	node * prev = NULL;
	node * prevRating = NULL;
	node * curr = headByName;
    node * currRating = headByRating;
	
	while (curr)
	{
		if(strcmp(curr->item.getName(), name) == 0)
		{
			if(!prev)
			{
				headByName = curr->nextByName;
				
				}
			else
			{
				prev->nextByName = curr->nextByName;
			delete curr;
			//return true;
			}
		}

		prev = curr;
	
		curr = curr->nextByName;
		
	}
	//return false;




while (currRating)
	{
		if(strcmp(currRating->item.getName(), name) == 0)
		{
			if(!prevRating)
			{
				headByRating = currRating->nextByRating;
				
				}
			else
			{
				prevRating->nextByRating = currRating->nextByRating;
			delete currRating;
			return true;
			}
		}

		prevRating = currRating;
	
		currRating = currRating->nextByRating;
		
	}
	


	
	return false;


}
/**
* List: node constructor - initializer list
* in: winery
* out: none
* return: none
**/
list::node::node(const winery &winery) : item(winery.getName(), winery.getLocation(), winery.getAcres(), winery.getRating())

{

	nextByName = NULL;
	nextByRating = NULL;
	


}
