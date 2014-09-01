#include <vld.h>
#include <iostream>

// enable Visual C++ memory leak checking
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include "winery.h"
#include "list.h"

using namespace std;

int main()
{

    list	*wineries = new list();
	winery	*wPtr;

    cout << "\nCorey Mattis" << endl << endl;

	wineries->insert(winery("Lopez Island Vinyard", "San Juan Islands", 7, 95));
	wineries->insert(winery("Gallo", "Napa Valley", 200, 25));
	wineries->insert(winery("Cooper Mountain", "Willamette Valley", 100, 47));
	wineries->insert(winery("Duck Pond Cellars", "Willamette Valley", 845, 70));
	wineries->insert(winery("Del Rio", "Bear Creek Valley", 200, 37));
	wineries->insert(winery("Weisinger's of Ashland", "Bear Creek Valley", 6, 83));
	wineries->insert(winery("LongSword", "Applegate Valley", 16, 85));

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> removing Cooper Mountain\n";
	wineries->remove("Cooper Mountain");

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> inserting San Juan Vinyards\n";
	wineries->insert(winery("San Juan Vinyards", "San Juan Islands", 20, 90));

	cout << "\n+++ list by name\n";
	wineries->displayByName(cout);
	cout << "\n+++ list by rating\n";
	wineries->displayByRating(cout);

	cout << "\n>>> search for \"Gallo\"\n\n";
	wPtr = wineries->find("Gallo");
	if (wPtr != 0)
		cout << wPtr;
	else
		cout << "not found" << endl;

	cout << "\n>>> search for \"No Such\"\n\n";
	wPtr = wineries->find("No Such");
	if (wPtr != 0)
		cout << wPtr;
	else
		cout << "not found" << endl;

	cout << endl;

	delete wineries;

// in Visual Studio, reports on memory leaks in the Output window
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
