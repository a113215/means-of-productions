#include "FlightStrategyClass.h"

FlightStrategyClass::FlightStrategyClass()
{
	//Ĭ���״�򿪡�����ģʽ��ʼ��������Ϊ0
	m_output.m_FlyCtrlCmd.m_fStickLat = 0.0f;
	m_output.m_FlyCtrlCmd.m_fStickLon = 0.0f;
	m_output.m_FlyCtrlCmd.m_fThrottle = 0.0f;
	m_output.m_FlyCtrlCmd.m_fRudder = 0.0f;
	m_output.m_FCCtrlCmd.m_eMainTaskMode= Enum_AircraftTaskMode_WVR;
	m_output.m_RadarCtrlCmd.m_eRadarOnOff = Enum_RadarOnOff_ON;
	m_output.m_RadarCtrlCmd.m_fEleScanCent = 0;
}

FlightStrategyClass::~FlightStrategyClass()
{

}

AIPilotOutput  FlightStrategyClass::LevelOff(const AIPilotInput * input, LevelStrategy strategy)
{
	//���˼·��
	//		����1��
	//			���ٶȴ���ƽ���ٶ�ʱ----���˽�����תΪ���ܽ�������ƽ��()
	//			���ٶ�С��ƽ���ٶ�ʱ----���˽�����תΪ���ܽ�������ƽ��
	//		����2��
	//			���ٶȴ���ƽ���ٶ�ʱ----���˱��ָ߶Ȳ���(�ܺ����)
	//			���ٶ�С��ƽ���ٶ�ʱ----�Ӵ����Ų�ͨ�����˱��ָ߶Ȳ������մﵽƽ���ٶȼ�С����
	int minVeloc = m_data.MinLevelVeloc(input->m_AircraftMoveInfo.m_dSelfAlt),
		maxVeloc = m_data.MaxLevelVeloc(input->m_AircraftMoveInfo.m_dSelfAlt);
	//ƽ�ɸ�����Χѡ�񱣻�[-PITCH_LIMIT,PITCH_LIMIT]:��Χ�����̻����ݸ���0
	switch (strategy)
	{
	case KeepEnergy:
		m_output.m_FlyCtrlCmd.m_fThrottle = 0;
		//������Ϊ0�������ü��١������ü���;����0.1���ݶȣ����ٶȴ���ƽ���ڿ�ʼ�𽥽��ɻ�����ƽ��(ƽ���Թ��Ǹ�����)
		if (((maxVeloc < input->m_AircraftMoveInfo.m_fMach*MATIMES))){
			m_output.m_FlyCtrlCmd.m_fStickLon = GRADS;
			if (input->m_AircraftMoveInfo.m_fPitch >= PITCH_LIMIT)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0;
		}
		else if (minVeloc > input->m_AircraftMoveInfo.m_fMach*MATIMES) {
			m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS;
			if (input->m_AircraftMoveInfo.m_fPitch >= PITCH_LIMIT)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0;
		}
		else
		{
			//�ƶ���ת�����---��ʼƽ�ȷɻ�
			if (input->m_AircraftMoveInfo.m_fAccU > 0)
				m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS;
			else 
				m_output.m_FlyCtrlCmd.m_fStickLon = GRADS;
			if (input->m_AircraftMoveInfo.m_fPitch<GRADS || input->m_AircraftMoveInfo.m_fPitch>-GRADS)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0;
		}
		break;

	case KeepAlt:break;
	}
	return m_output;
}

AIPilotOutput FlightStrategyClass::Track(const AIPilotInput * input)
{
	//���˼·���������ٶȷ����λ�ƴ���ͬһ����
	//ֻ�����״�̽�⵽��Ŀ��
	//����Ŀ�귽λ�ǡ������ǡ������ٶȺ�������ٶȻ�ȡ��������ѿ��Ʋ���
	//��λ�ǣ���ʱ��Ϊ��
	//�����ǣ�̧ͷΪ��
	bool azis = false, aEle = false;
	//����1��Ŀ�궪ʧ����ƽ�ȷ��в���
	if (input->m_RadarInfo.m_uiTgtNum > 0)
	{
		if (input->m_RadarInfo.m_TgtInfo->m_fTgtAzi > ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fRudder = GRADS;
		else if (input->m_RadarInfo.m_TgtInfo->m_fTgtAzi < -ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fRudder = -GRADS;
		else
		{
			m_output.m_FlyCtrlCmd.m_fRudder = 0;
			azis = true;
		}
			
		if (input->m_RadarInfo.m_TgtInfo->m_fTgtEle > ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fStickLon = GRADS;
		else if (input->m_RadarInfo.m_TgtInfo->m_fTgtEle < -ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS;
		else
		{
			m_output.m_FlyCtrlCmd.m_fStickLon = 0;
			aEle = true;
		}
		if (input->m_RadarInfo.m_TgtInfo->m_fTgtDisDot < 0)
			m_output.m_FlyCtrlCmd.m_fThrottle += GRADS;
		if (azis && aEle)
			JustifyPose(input);
	}
	else
		LevelOff(input,KeepEnergy);
	//input->m_RadarInfo.m_TgtInfo->m_fTgtAzi;
	//����2��ͨ���ݸ˸ı䱾��������������Ŀ�귽λ��
	return m_output;
}

void FlightStrategyClass::FireStratgy(const AIPilotInput * input)
{
}

void FlightStrategyClass::RadderScan(const AIPilotInput * input)
{
}

void FlightStrategyClass::JustifyPose(const AIPilotInput * input)
{
	//���Ǳ仯
	if (input->m_AircraftMoveInfo.m_fAlpha > ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS;
	else if(input->m_AircraftMoveInfo.m_fAlpha < -ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fStickLon = GRADS;
	else
		m_output.m_FlyCtrlCmd.m_fStickLon = 0;
	//�໬�Ǳ仯
	if (input->m_AircraftMoveInfo.m_fBeta > ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fRudder = -GRADS;
	else if (input->m_AircraftMoveInfo.m_fBeta < -ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fRudder = GRADS;
	else
	{
		m_output.m_FlyCtrlCmd.m_fRudder = 0;
		if (input->m_AircraftMoveInfo.m_fRoll > ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fStickLat = -GRADS;
		else if (input->m_AircraftMoveInfo.m_fRoll < -ERRORRANGE)
			m_output.m_FlyCtrlCmd.m_fStickLat = GRADS;
		else
			m_output.m_FlyCtrlCmd.m_fStickLat = 0;
	}
	//���ű仯
	if (input->m_AircraftMoveInfo.m_fAccU < -ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fThrottle += GRADS;
	else if (input->m_AircraftMoveInfo.m_fAccU > ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fThrottle -= GRADS;
}
