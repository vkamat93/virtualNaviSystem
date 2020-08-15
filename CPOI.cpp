#include "CPOI.h"
#include "CWaypoint.h"
#include "CGPSSensor.h"
/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOI.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

//System Include Files

//Own Include Files
//Method Implementations
void CPOI::print()
{
	cout << "Point of Interest" << endl << "==============" << endl;

/*To get appropriate statement depending on the enum type of POI*/
	switch (m_type)
	{
	case RESTAURANT:
		cout << "of type Restaurant : " << m_description << endl;
		break;

	case SIGHTSEEING:
		cout << "of type Sightseeing : " << m_description << endl;
		break;

	case SHOPPING:
		cout << "of type Shopping: " << m_description << endl;
		break;

	default:
		cout << "NO such type found" << endl;
	};

	/*The 'this' is used to specify that the print function called via the object of CPOI
	 * such that we get values of CPOI in the format same as one in CWaypoint*/
	this->CWaypoint::print(MMSS);
}

CPOI::CPOI(t_poi type, string name, string description, double latitude,
		double longitude)
{
	m_type = type;
	m_description = description;
	m_name = name;
	m_latitude = latitude;
	m_longitude = longitude;
	/* If no inheritance was used then we would have used
	 * set(name,latitude,longitude ) for name,latitude and longitude
	 * intead of direct assignment*/
}

void CPOI::getAllDataByReference(string& name, double& latitude,
		double& longitude, t_poi& type, string& description)
{
/*here getname().etc function would have been compulsory when m_longitude would have been
 * private but here direct assignment also works since these are protected and inherited*/
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;
}
