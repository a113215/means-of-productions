#include "FlightStrategyClass.h"

FlightStrategyClass::FlightStrategyClass()
{
	m_output = new AIPilotOutput();
}

FlightStrategyClass::~FlightStrategyClass()
{
	delete m_output;
}
