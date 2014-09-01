#include <iostream>
#include <iomanip>
// enable Visual C++ memory leak checking
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "winery.h"

using namespace std;

/**
* List: constructor
* in: name, location, acres, rating
* out: none
* return: name, location, acres, rating
**/
winery::winery(const char * const name, const char * const location, const int acres, const int rating): name( new char[strlen(name)+1] ), location( new char[strlen(location)+1] ),acres(0),rating(0)
{

	strcpy( this->name,  name );
	strcpy( this->location, location );
	this->acres = acres;
	this->rating = rating;
	
	

}

/**
* List: destructor
* in: none
* out: none
* return: none
**/
winery::~winery()
{

	if(name)
	  
		delete[] name;
	if(location)
		delete[] location;
	

}

/**
* winery : getname
* in: none
* out: none
* return: name
**/
const char * const winery::getName() const
{

	strcpy( this->name, name );
	return name;

}

/**
* winery : getlocation
* in: none
* out: none
* return: location
**/
const char * const winery::getLocation() const
{
	return location;
}

/**
* winery : getacres
* in: none
* out: none
* return: acres
**/
const int winery::getAcres() const
{

	return acres;
}

/**
* winery : getRating
* in: none
* out: none
* return: rating
**/
const int winery::getRating() const
{

	return rating;

}

/**
* winery : display headings
* in: ostream
* out: none
* return: name
**/
void winery::displayHeadings(ostream& out)
{

    out << endl;
    out << right;
	out << "Name  " << ' '
		<< setw(29)<< "Location  " << setw(17)
		<< "Acre  " << setw(10)
		<< "Rating  " << endl;
	out << right;
	out << "-----" 
	    << setw(29) << "--------" << ' '
		<< setw(16) << "----" << ' '
		<< setw(9) << "------" << endl;


}
/**
* winery : Overloaded operator
* in: ostream, winery
* out: name,location,acres,rating
* return: out
**/
ostream& operator<<(ostream& out, winery *w)
{

    out << left
        << setw(25) << w->getName()     << ' '
        << setw(21) << w->getLocation() << ' '
        << left
        << setw(10)  << w->getAcres()    << ' '
        << setw(9)  << w->getRating()   << '\n';
     

	return out;
}
