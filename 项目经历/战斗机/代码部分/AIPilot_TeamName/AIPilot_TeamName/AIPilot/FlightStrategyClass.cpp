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
	int altitude = (((int)input->m_AircraftMoveInfo.m_dSelfAlt / 1000)%2 == 0)?((int)input->m_AircraftMoveInfo.m_dSelfAlt)-1: (int)input->m_AircraftMoveInfo.m_dSelfAlt;
	if (altitude == 0)
		altitude = 1;
	else if (altitude > 15)
		altitude = 15;
	int minVeloc = m_data.MinLevelVeloc(altitude),
		maxVeloc = m_data.MaxLevelVeloc(altitude);
	//ƽ�ɸ�����Χѡ�񱣻�[-PITCH_LIMIT,PITCH_LIMIT]:��Χ�����̻����ݸ���0
	switch (strategy)
	{
	case KeepEnergy:
		m_output.m_FlyCtrlCmd.m_fThrottle = 0;
		//������Ϊ0�������ü��١������ü���;����0.1���ݶȣ����ٶȴ���ƽ���ڿ�ʼ�𽥽��ɻ�����ƽ��(ƽ���Թ��Ǹ�����)
		if (((maxVeloc < input->m_AircraftMoveInfo.m_fMach*MATIMES))){
			m_output.m_FlyCtrlCmd.m_fStickLon = GRADS*5;
			if (input->m_AircraftMoveInfo.m_fPitch >= PITCH_LIMIT)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0;
		}
		else if (minVeloc > input->m_AircraftMoveInfo.m_fMach*MATIMES) {
			m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS*5;
			if (input->m_AircraftMoveInfo.m_fPitch <= -PITCH_LIMIT)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0;
		}
		else
		{
			//�ƶ���ת�����---��ʼƽ�ȷɻ�
			JustifyPose(input);
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
	//����Ŀ�������ٶȺ�������ٶȻ�ȡ��������ѿ��Ʋ���
	//��λ�ǣ���ʱ��Ϊ��
	//�����ǣ�̧ͷΪ��
	//����1��Ŀ�궪ʧ����ƽ�ȷ��в���
	//����2��Ŀ��δ��ʧ�������ɻ������ǺͲ໬������л�ͬ��,����������
	int northVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVN - input->m_AircraftMoveInfo.m_fAccN,
		upVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVU - input->m_AircraftMoveInfo.m_fAccU,
		earthVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVE - input->m_AircraftMoveInfo.m_fAccE;
	if (input->m_RadarInfo.m_uiTgtNum > 0)
	{
		//�����ɻ���̬����ͬ��̬
	/*	m_output.m_FlyCtrlCmd.m_fRudder = m_data.StickRudder(input->m_RadarInfo.m_TgtInfo->m_fTgtAzi);
		m_output.m_FlyCtrlCmd.m_fStickLon = m_data.StickLon(input->m_RadarInfo.m_TgtInfo->m_fTgtEle);*/
		if (input->m_RadarInfo.m_TgtInfo->m_fTgtEle > ERRORRANGE)
		{
			m_output.m_FlyCtrlCmd.m_fStickLon = 1.0f;
			if(input->m_AircraftMoveInfo.m_fPitch >= PITCH_LIMIT*2)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0.0f;
		}
		else if(input->m_RadarInfo.m_TgtInfo->m_fTgtEle < -ERRORRANGE){
			m_output.m_FlyCtrlCmd.m_fStickLon = -1.0f;
			if (input->m_AircraftMoveInfo.m_fPitch <= -PITCH_LIMIT*2)
				m_output.m_FlyCtrlCmd.m_fStickLon = 0.0f;
		}
		else
		{
			m_output.m_FlyCtrlCmd.m_fStickLon = m_data.StickLon(input->m_RadarInfo.m_TgtInfo->m_fTgtEle);
		}
			
		if (input->m_RadarInfo.m_TgtInfo->m_fTgtAzi > ERRORRANGE)
		{
			m_output.m_FlyCtrlCmd.m_fRudder += 1.0f;
		}
		else if(input->m_RadarInfo.m_TgtInfo->m_fTgtAzi <- ERRORRANGE)
		{
			m_output.m_FlyCtrlCmd.m_fRudder = -1.0f;
		}
		else
		{
			m_output.m_FlyCtrlCmd.m_fRudder = m_data.StickRudder(input->m_RadarInfo.m_TgtInfo->m_fTgtAzi);
		}
		//���������ٶ����Ӷ�Ӧ�Ƕ�
		/*if (abs(northVeloc) >= abs(upVeloc) && abs(northVeloc) >= abs(earthVeloc))
		{
			int sign = (northVeloc > 0) ? 1 : -1;
			if(input->m_RadarInfo.m_TgtInfo->m_fTgtAzi > 0)
				m_output.m_FlyCtrlCmd.m_fRudder += sign * GRADS * 10;
			else
				m_output.m_FlyCtrlCmd.m_fRudder -= sign * GRADS * 10;
		}
		else if (abs(upVeloc) >= abs(northVeloc) && abs(upVeloc) >= abs(earthVeloc))
		{
			int sign = (upVeloc > 0) ? 1 : -1;
			if(input->m_RadarInfo.m_TgtInfo->m_fTgtEle >0)
				m_output.m_FlyCtrlCmd.m_fStickLon += sign * GRADS * 10;
			else
				m_output.m_FlyCtrlCmd.m_fStickLon -= sign * GRADS * 10;
		}
		else
		{
			int sign = (earthVeloc > 0) ? 1 : -1;
			if (input->m_RadarInfo.m_TgtInfo->m_fTgtAzi > 0)
				m_output.m_FlyCtrlCmd.m_fRudder += sign * GRADS * 10;
			else
				m_output.m_FlyCtrlCmd.m_fRudder -= sign * GRADS * 10;
		}*/
		m_output.m_FlyCtrlCmd.m_fThrottle = 1.0f;
		/*if (input->m_RadarInfo.m_TgtInfo->m_fTgtDisDot < 0)
			m_output.m_FlyCtrlCmd.m_fThrottle += GRADS*5;*/
		
	}
	else
		JustifyPose(input);
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
AIPilotOutput FlightStrategyClass::LevelThrottle(const AIPilotInput * input)
{
	if ((input->m_AircraftMoveInfo.m_fVN * input->m_AircraftMoveInfo.m_fAccN +
		input->m_AircraftMoveInfo.m_fVE * input->m_AircraftMoveInfo.m_fAccE) < 0)
		m_output.m_FlyCtrlCmd.m_fThrottle += GRADS;
	return m_output;
}

AIPilotOutput FlightStrategyClass::JustifyPose(const AIPilotInput * input)
{
	//���Ǳ仯�������ǣ�
	m_output.m_FlyCtrlCmd.m_fStickLon = m_data.StickLon(input->m_AircraftMoveInfo.m_fPitch);
	//�໬�Ǳ仯
	m_output.m_FlyCtrlCmd.m_fRudder = m_data.StickRudder(input->m_AircraftMoveInfo.m_fYaw);
	//��ת�Ǳ仯
	m_output.m_FlyCtrlCmd.m_fStickLat = m_data.StickLat(input->m_AircraftMoveInfo.m_fRoll);
	//���ű仯
	LevelThrottle(input);
	return m_output;
}
