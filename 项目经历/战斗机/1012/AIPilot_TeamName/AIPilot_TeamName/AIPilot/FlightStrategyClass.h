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
	*/
	AIPilotOutput* Hover(AIPilotInput *input);
	/*
	brief ׷�ٲ���
	*/
	AIPilotOutput* Track(AIPilotInput *input);
private:
	/*
	brief �������
	*/
	void FireStratgy(AIPilotInput * input);
	/*
	brief �״�ɨ�����
	*/
	void RadderScan(AIPilotInput * input);
	/*
	brief ����׷��Ŀ���Ҳ���ʧ�����µ�ֵ�������Ӿ��ڿ��ã�
	*/
	void Internal(AIPilotInput * input)
};

