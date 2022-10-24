#include "FlightParaDataClass.h"

FlightParaDataClass::FlightParaDataClass()
{
	FormatLevelVeloc();
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

float FlightParaDataClass::StickLon(float pitchSpan)
{
	//俯仰值和纵杆强度图像上表示为k=-1/PI，且过原点的直线 
	float pitch;
	if (pitchSpan / PI * 10 > 1)
		pitch = -1.0f;
	else if (pitchSpan / PI * 10 < -1)
		pitch = 1.0f;
	else
		pitch = -pitchSpan / PI * 10;
	//设定抬头，不下降
	if ((pitchSpan < ERRORRANGE && pitchSpan >= 0)||
		(pitchSpan > -ERRORRANGE && pitchSpan <= 0))
		pitch = 0.1f;
	return pitch;
}


float FlightParaDataClass::StickRudder(float yawSpan)
{
	//脚蹬强度和偏航值图像上表示为k=-1/PI，且过原点的直线 
	float rudder;
	if (yawSpan / PI * 10 > 1)
		rudder = -1.0f;
	else if (yawSpan / PI * 10 < -1)
		rudder = 1.0f;
	else
		rudder = -yawSpan / PI * 10;
	////设定脚蹬
	//if ((yawSpan < ERRORRANGE && yawSpan > 0) ||
	//	(yawSpan > -ERRORRANGE && yawSpan < 0))
	//	rudder = 0.1f;

	return rudder;
}

float FlightParaDataClass::StickLat(float rollSpan)
{
	//翻转强度和偏航值图像上表示为k=-1/PI，且过原点的直线 
	float roll;
	if (rollSpan / PI * 10 > 1)
		roll = -1.0f;
	else if (rollSpan / PI * 10 < -1)
		roll = 1.0f;
	else
		roll = -rollSpan / PI * 10;
	return roll;
}
/*float FlightParaDataClass::StickThrottle(float veloc,float velocSpan, int altitude)
{
	if (velocSpan < 0)
		return 0.0f;
	if (altitude > 15 || (veloc + velocSpan) > 2)
		return 1.0f;
	switch (altitude)
	{
	case 0:
	case 1:
	case 2:
		if (veloc >= 0.95f)
			return 0.0f;
		else if (veloc + velocSpan > 0.95)
			return 0.63f;
	case 3:
	case 4:
	case 5:
		if (veloc < 0.95 && velocSpan == 0)
			return 0.63f;
	case 6:
	case 7:
	case 8:
	case  9:
		if (veloc < 0.95)
			return 0.65f;
		else
			return 1.0f;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		return 1.0f;
		break;
	}
	return 0.0f;
}*/

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
