#include "FlightStrategyClass.h"

FlightStrategyClass::FlightStrategyClass()
{
	m_output = new AIPilotOutput();
}

FlightStrategyClass::~FlightStrategyClass()
{
	delete m_output;
}

AIPilotOutput * FlightStrategyClass::Track(AIPilotInput * input)
{
	//���˼·���������ٶȷ����λ�ƴ���ͬһ����
	//ֻ�����״�̽�⵽��Ŀ��
	//����Ŀ�귽λ�ǡ������ǡ������ٶȺ�������ٶȻ�ȡ��������ѿ��Ʋ���
	//��λ�ǣ���ʱ��Ϊ��
	//�����ǣ�̧ͷΪ��
	//����1��Ŀ�겻��ʧ�ı�������Ϣ����ֵ����λ�Ǹ�������ͬ����λ�Ǹ����Ǵ����״��̽���Ե��

	//����1��ͨ���ŵŸı䱾��ƫ����������Ŀ�귽λ��
	input->m_RadarInfo.m_TgtInfo->m_fTgtAzi
	//����2��ͨ���ݸ˸ı䱾��������������Ŀ�귽λ��
	return nullptr;
}
