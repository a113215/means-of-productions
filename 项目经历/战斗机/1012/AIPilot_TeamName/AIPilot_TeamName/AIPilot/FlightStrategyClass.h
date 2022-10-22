#pragma once
#include"AI_Interface.h"
#include "FlightParaDataClass.h"
#define GRADS 0.1
#define ERRORRANGE 0.01
#define PITCH_LIMIT 3.14159/6.0
class FlightStrategyClass
{
public:
	enum LevelStrategy {KeepEnergy=0,KeepAlt=1};
	AIPilotOutput m_output;
	FlightStrategyClass();
	~FlightStrategyClass();
	/*
	brief 平飞
	param 参数1 input 仿真平台输入信息
	param 参数2 strategy 策略选择（见实现）
	*/
	AIPilotOutput LevelOff(const AIPilotInput *input, LevelStrategy strategy);
	/*
	brief 盘旋飞行策略
	*/
	AIPilotOutput Hover(const AIPilotInput *input);
	/*
	brief 追踪策略
	*/
	AIPilotOutput Track(const AIPilotInput *input);
	/*
		brief 保持平稳高度飞行下，改变飞机姿态至侧滑角未0攻角0
	*/
	void JustifyPose(const AIPilotInput * input);
private:
	/*
	brief 开火策略
	*/
	void FireStratgy(const AIPilotInput * input);
	/*
	brief 雷达扫描策略
	*/
	void RadderScan(const AIPilotInput * input);

	AIPilotInput *m_limitOutput;
	FlightParaDataClass m_data;
};

