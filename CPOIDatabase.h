/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"

//This class is used to make a database of the POIs and store all their details
class CPOIDatabase
{
private:
/*Initializing an array of 10 elements of type CPOI*/
    CPOI m_POI[10];
/*Int to keep track of number of POIs stored*/
    int m_noPoi;
public:

/*Default Constructor
 *@return no return type in Constructor */
    CPOIDatabase();

/*This function adds the POIs to the database one by one
 *@param type used for enum type of POI
 *@param name used to store the name of the POI
 *@param description used to store the description of the POI
 *@param latitude used to store the latitude of POI
 *@param longitude used to store the longitude of POI
 *@return returns void*/
    void addPoi(t_poi type, string name, string description, double latitude, double longitude);

/*This function is used to check whether desired POI in route exists in the Database
 *@param name to get a name of the POI which is to be checked for existence in Database
 *@return returns a pointer of type CPOI*/
    CPOI* getPointerToPoi(string name);
};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
