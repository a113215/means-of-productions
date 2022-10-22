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
	brief ƽ��
	param ����1 input ����ƽ̨������Ϣ
	param ����2 strategy ����ѡ�񣨼�ʵ�֣�
	*/
	AIPilotOutput LevelOff(const AIPilotInput *input, LevelStrategy strategy);
	/*
	brief �������в���
	*/
	AIPilotOutput Hover(const AIPilotInput *input);
	/*
	brief ׷�ٲ���
	*/
	AIPilotOutput Track(const AIPilotInput *input);
	/*
		brief ����ƽ�ȸ߶ȷ����£��ı�ɻ���̬���໬��δ0����0
	*/
	void JustifyPose(const AIPilotInput * input);
private:
	/*
	brief �������
	*/
	void FireStratgy(const AIPilotInput * input);
	/*
	brief �״�ɨ�����
	*/
	void RadderScan(const AIPilotInput * input);

	AIPilotInput *m_limitOutput;
	FlightParaDataClass m_data;
};

