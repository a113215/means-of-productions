#include "FlightParaDataClass.h"

FlightParaDataClass::FlightParaDataClass()
{
	
}

int FlightParaDataClass::FireRange(float veloc, int angle, int altitude, Mode mode)
{
	return 0;
}

int FlightParaDataClass::MinLevelVeloc(int altitude,Mode mode)
{

	if (mode == 0)
		return m_minLevelVeloc[altitude];
	return 0;

}

int FlightParaDataClass::MaxLevelVeloc(int altitude,  Mode mode)
{
	if (mode == 0)
		return m_maxLevelVeloc[altitude];
	return 0;
}


void FlightParaDataClass::FormatRanges()
{

}

void FlightParaDataClass::FormatLevelVeloc()
{
	//全加力情况下
	m_minLevelVeloc.insert(pair<int,int>(1, 20));
	m_minLevelVeloc.insert(pair<int, int>(3, 23));
	m_minLevelVeloc.insert(pair<int, int>(5, 26));
	m_minLevelVeloc.insert(pair<int, int>(7, 29));
	m_minLevelVeloc.insert(pair<int, int>(9, 32));
	m_minLevelVeloc.insert(pair<int, int>(11, 40));
	m_minLevelVeloc.insert(pair<int, int>(13, 48));
	m_minLevelVeloc.insert(pair<int, int>(15, 56));

	m_maxLevelVeloc.insert(pair<int, int>(1, 125));
	m_maxLevelVeloc.insert(pair<int, int>(3, 138));
	m_maxLevelVeloc.insert(pair<int, int>(5, 154));
	m_maxLevelVeloc.insert(pair<int, int>(7, 173));
	m_maxLevelVeloc.insert(pair<int, int>(9, 195));
	m_maxLevelVeloc.insert(pair<int, int>(11,205));
	m_maxLevelVeloc.insert(pair<int, int>(13, 205));
	m_maxLevelVeloc.insert(pair<int, int>(15, 205));
}
