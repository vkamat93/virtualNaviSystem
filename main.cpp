// GIT-Labor
// main.h

////////////////////////////////////////////////////////////////////////////////
// Header-Dateien
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
#include <stdlib.h>
#include "CWayPoint.h"
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPOIDatabase.h"
#include "CRoute.h"
#include "CNavigationSystem.h"

// TODO: Fügen Sie hier weitere benötigte Header-Dateien der
// Standard-Bibliothek ein z.B.
// #include <string>

using namespace std;	// Erspart den scope vor Objekte der
						// C++-Standard-Bibliothek zu schreiben
						// z.B. statt "std::cout" kann man "cout" schreiben

// Inkludieren Sie hier die Header-Files Ihrer Klassen, z.B.
// #include "CFraction.h"


// Hauptprogramm
// Dient als Testrahmen, von hier aus werden die Klassen aufgerufen
int main (void)
{

/*assigning garbage values to local variables to test condition(h) of exercise 1.1*/
	string name="hh";
/*assigning garbage values to local variables to test condition(h) of exercise 1.1*/
    double latitude=88.88,longitude=99.99;

/*Creating object of CWaypoint*/
	CWaypoint berlin("berlin", 52.5166, 13.4);
/*Printing the details of berlin in both formats*/
    berlin.print(DEGREE);
	berlin.print(MMSS);

/*Creating another object of CWaypoint*/
	CWaypoint amsterdam("amsterdam", 52.3667, 4.9000);

/*Creating another object of CWaypoint*/
    CWaypoint darmstadt("darmstadt", 49.8667, 8.6500);

/*Creating another object of CWaypoint*/
    CWaypoint tokio("tokio", 35.6833, 139.6833);

/*Testcase for default values of the constructor*/
	 CWaypoint newWaypoint;
	 newWaypoint.print(DEGREE);
	 newWaypoint.print(MMSS);

cout<<"and a first real method"<<endl<<"======================="<<endl;
/*Testcase for distance between Berlin to Amsterdam*/
		cout<<"Distance between Amsterdam and Berlin :"
				<<berlin.calculateDistance(amsterdam)<<endl;

/*Testcase for distance between Berlin to Tokio*/
		cout<<"Distance between Tokio and Berlin :"
			<<berlin.calculateDistance(tokio)<<endl;

/* The addresses and values of the local variables name, latitude and longitude
 * are exactly  the same as that of the parameter addresses and values since,
 * we have used the call by reference method which uses reference to address of
 * the variable to  store the values */
tokio.getAllDataByReference(name,latitude,longitude);


/*Creating an object of class CNavigationSystem*/
CNavigationSystem cnav;

/*Calling run() func using object of CNavigationSystem*/
cnav.run();

return 0;
}
