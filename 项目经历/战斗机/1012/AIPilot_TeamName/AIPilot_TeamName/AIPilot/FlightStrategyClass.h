#pragma once
#include"AI_Interface.h"
class FlightStrategyClass
{
public:
	AIPilotOutput* m_output;
	FlightStrategyClass();
	~FlightStrategyClass();
	/*
	brief 盘旋飞行策略
	param	rudder		参数1：脚蹬位移[-1,1]
	param	stickLon	参数2：纵向杆位移[-1,1]
	return	void
	*/
	AIPilotOutput* Hover(AIPilotInput *input);
	AIPilotOutput* Track(AIPilotInput *input);
private:
	void FireStratgy(AIPilotInput * input);
};

