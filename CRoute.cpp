/*
 * CRoute.cpp0
 *
 *  Created on: 07-Nov-2015
 *      Author: VIKRANT
 */

#include "CRoute.h"
#include <iostream>
using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi)
{

	m_nextWp = 0;
	m_nextPoi = 0; //initialization to 0 for the variable

	//Allocate memory for the storing waypoints at runtime
	m_pWaypoint = new CWaypoint[maxWp];

	//Allocate memory for storing CPOIs at runtime
	m_pPoi = new CPOI*[maxPoi];

	m_maxWp = maxWp;
	m_maxPoi = maxPoi;

	/*Initially it must contain no address so that it will later get address of object
	 *passed for connecting Database*/
	m_pPoiDatabase = NULL;
}

//This is a copy constructor, but for scope of this assignment remains unused
CRoute::CRoute(CRoute const& origin)
{
//to copy data which is passed in parameter object

    m_nextWp = origin.m_nextWp;
    m_nextPoi = origin.m_nextPoi;
    m_maxWp = origin.m_maxWp;
	m_maxPoi = origin.m_maxPoi;
	m_pPoiDatabase = origin.m_pPoiDatabase;

   m_pWaypoint = new CWaypoint[m_maxWp];
   for(unsigned int i=0; i<m_maxWp; i++)
   {
   m_pWaypoint[i]=origin.m_pWaypoint[i]; //copies the values in the new dynamic memory
   }

   m_pPoi = new CPOI*[m_maxPoi];
   for(unsigned int i=0; i<m_maxPoi; i++)
   {
   m_pPoi[i]=origin.m_pPoi[i]; //copies the values in the new dynamic memory
   }
}

void CRoute::connectToPoiDatabase(CPOIDatabase* pPoiDB = NULL)
{
/*here we want the address of the database so in CNavigationSystem we have object of
 * database and &object gives address of 'real database' which is then
 * assigned to m_pPoiDatabase*/

/*pass address of object of database to the the database pointer present here in
* CRoute but currently not pointing anywhere,ie,NULL pointer*/
	m_pPoiDatabase = pPoiDB;

}

void CRoute::addWayPoint(CWaypoint const& wp)
{
	if (m_nextWp < m_maxWp)
	{
		//this is wrong! m_pWaypoint[m_nextWp]= wp.getName(); cuz not just the name also the lat and long is stored
		m_pWaypoint[m_nextWp] = wp;
		m_nextWp++;
	}
	else
	{
		cout << "Error: Number of Waypoints entered exceeds max Waypoint limit" << endl;
	}

}

void CRoute::addPoi(string namePoi)
{
	/*To check if m_pPoiDatabase holds address of the database,i.e database connected*/
	if(m_pPoiDatabase!=NULL)
	{
      /*Condition check to ensure that only the predefined max. number of POIs
       * can be given on our route */
	   if (m_nextPoi < m_maxPoi)
	  {
		/*this is beacause m_pPoi is a pointer which points to array of pointers and these
		 * pointers point to array of objects in database*/
		 m_pPoi[m_nextPoi] = m_pPoiDatabase->getPointerToPoi(namePoi);

       /*to check whether a POI on the route is indeed found in database, only then
        * increment the position of the pointer array, used later in Distance calculation
        * to check whether a POI is present to calculate distance*/
		if(m_pPoi[m_nextPoi]!=NULL)
		{
			m_nextPoi++;
		}
	  }
	   else
	  {
		cout << "Error: number of POIs entered exceeds max POI limit" << endl;
	  }
	}
	/*If the database is not connected or some NULL pointer error occurs*/
	else
	{
		cout<<"Error:POI database not connected"<<endl;
	}
}

double CRoute::getDistanceNextPoi(CWaypoint const& wp, CPOI& poi)
{
	/*If condition to check whether there are POIs specified on the route*/
	if(m_nextPoi!=0)
	{
	/*CPOI inherits CWaypoint so all its functions too and thus
	 * we use this function to calculate distance*/
	double smallestDist = m_pPoi[0]->calculateDistance(wp);

	int count = 0;  //variable to store array location of the nearest POI details
	for (unsigned int i = 0; i < m_nextPoi; i++)
	{
		if (smallestDist > m_pPoi[i]->calculateDistance(wp))
		{
			smallestDist = m_pPoi[i]->calculateDistance(wp);
			count = i;
		}
	}
	poi = *m_pPoi[count]; //to get the details of the nearest POI
	return smallestDist;
	}
	/*If there is no POI specified on route return a dummy value in control logic
	 * used later for printing a error message in Distance calculation   */
	else
	{
		return -1.0;
	}
}

void CRoute::print()
{
/*Using the m_nextWp and m_nextPoi instead of m_maxWp because it takes the actual
 * number of POIs and Waypoints present instead of just the max value allocated*/
cout << "Our route has " << m_nextWp << " Waypoints and " << m_nextPoi
			<< " points of interest" << endl;

/*To get the details of Waypoints on our route*/
	for (unsigned int i = 0; i < m_nextWp; i++)
	{
		/*m_pWaypoint is pointer which points to array of objects, thus we can use the
		 * dot(.) to access the print function of that object */
		m_pWaypoint[i].print(MMSS);
	}

/*To get the details of POIs on our route*/
	for (unsigned int i = 0; i < m_nextPoi; i++)
	{
		/*here the m_pPoi is an array of pointers, thus m_pPoi[i] is itself a pointer
		 * thus to access a function of the object which it is pointing to we use (->)*/
		m_pPoi[i]->print();
	}
}

CRoute::~CRoute()
{
	/*release the dynamic memory from use*/
	delete m_pWaypoint;
	delete m_pPoi;

}

