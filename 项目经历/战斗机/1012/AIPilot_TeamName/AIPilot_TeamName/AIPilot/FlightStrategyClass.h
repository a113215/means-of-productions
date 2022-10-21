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
	*/
	AIPilotOutput* Hover(AIPilotInput *input);
	/*
	brief 追踪策略
	*/
	AIPilotOutput* Track(AIPilotInput *input);
private:
	/*
	brief 开火策略
	*/
	void FireStratgy(AIPilotInput * input);
	/*
	brief 雷达扫描策略
	*/
	void RadderScan(AIPilotInput * input);
	/*
	brief 生成追踪目标且不丢失条件下的值（仅在视距内可用）
	*/
	void Internal(AIPilotInput * input)
};

