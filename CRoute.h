/*
 * CRoute.h
 *
 *  Created on: 07-Nov-2015
 *      Author: VIKRANT
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include "CPOIDatabase.h"

/*This class does the job of linking the POI database, adding Waypoints and POIs,
 * printing them, calculating the closest POI and its distance from current location and
 * logic for error messages in this Navigation System*/
class CRoute
{
private:
/*Pointer variable of type CWaypoint*/
	CWaypoint* m_pWaypoint;

/*Unsigned int variable to store max value of the Waypoints in route*/
	unsigned int m_maxWp;

/*Unsigned int variable used for array location and further calculation*/
	unsigned int m_nextWp;

/*pointer variable of type CPOI which points to a location which has the addresses
 * of the POI objects created in the database, thus double pointer */
	CPOI** m_pPoi;

/*Unsigned int variable to store max value of the POIs in route*/
	unsigned int m_maxPoi;

/*Unsigned int variable used for array location and further calculation*/
	unsigned int m_nextPoi;

/*pointer variable of type CPOIDatabase*/
CPOIDatabase* m_pPoiDatabase;

public:
/*Constructor used to initialize the values of variables
 *@param maxWp used to pass the max number of Waypoints to be given in the route
 *@param maxPoi used to pass the max number of POIs to be given in the route
 *@return no return type for constructor*/
	CRoute(unsigned int maxWp, unsigned int maxPoi);

/*unused in this assignment*/
	CRoute(CRoute const& origin);

/*Connects with the POI database
 *@param pPoiDB is pointer of type CPOIDatabase which stores address of the passed object
 *       which is the POI database which we use.
 *@return returns void */
	void connectToPoiDatabase(CPOIDatabase* pPoiDB);

/*Adds Waypoints to our Route
 *@param &wp const object of type CWaypoint passed by reference
 *@return returns void*/
	void addWayPoint(CWaypoint const& wp);

/*Adds POIs to our Route
 *@param namePoi used to store the name to cross check in the database of POIs
 *@return returns void */
	void addPoi(string namePoi);

/* Used to calculate distance using the calculate distance formula defined
 * in CWaypoint and to return the shortest distance by smallest number algorithm
 *@return returns the distance to closest POI in double */
	double getDistanceNextPoi(CWaypoint const& wp,CPOI& poi);

/*Prints the waypoints and POIs in our route
 *@return returns void */
	void print();

/*Destructor used to delete the memory space allocated to the dynamic arrays created for
 * storing the Waypoints and POIs at runtime*/
	~CRoute();
};

#endif /* CROUTE_H_ */
