#pragma once
#include"AI_Interface.h"
class FlightStrategyClass
{
public:
	AIPilotOutput* m_output;
	FlightStrategyClass();
	~FlightStrategyClass();
	/*
	brief �������в���
	param	rudder		����1���ŵ�λ��[-1,1]
	param	stickLon	����2�������λ��[-1,1]
	return	void
	*/
	AIPilotOutput* Hover(AIPilotInput *input);
	AIPilotOutput* Track(AIPilotInput *input);
private:
	void FireStratgy(AIPilotInput * input);
};

