#include "CPOIDatabase.h"
#include "CPOI.h"

/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOIDATABASE.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

//System Include Files

//Own Include Files
//Method Implementations
CPOIDatabase::CPOIDatabase()
{
	/*ensuring that the initial position of the array is always set to 0 before addPoi()
	 * is invoked to avoid the crashing due to pointer pointing at undefined location*/
	m_noPoi = 0;
}

void CPOIDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude)
{

/*Condition to check if there is an attempt to add more POI objects to database than
 * the given max array size of m_POI */
	if(m_noPoi<10)
	{
		/*Stores the entire CPOI object as a single entry*/
		m_POI[m_noPoi] = CPOI(type, name, description, latitude, longitude);

		/*increments the location in the array*/
	    m_noPoi++;
	}
	else
	{
        //Error message in case >10 POI objects are attempted to be added
		cout<<"Only 10 POI allowed to be stored in database!!!"<<endl;
	}

}

CPOI* CPOIDatabase::getPointerToPoi(string name)
{
	CPOI* pointerToPoi = NULL; //set pointer to NULL before scanning the database

	/*Checking whether POI name on route is indeed in the POI database*/
	for (int i = 0; i < m_noPoi; i++)
	{
		if (m_POI[i].getName() == name)
		{
			pointerToPoi = &m_POI[i];
		}
	}
	if (pointerToPoi == NULL)
	{
		cout << "ERROR: Could not find POI Something not in the pool" << endl;
	}
	return pointerToPoi; //returns NULL pointer is no match
}
