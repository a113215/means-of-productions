#include "FlightStrategyClass.h"

FlightStrategyClass::FlightStrategyClass()
{
	//默认雷达打开、近距模式初始参数设置为0
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
	//设计思路：
	//		策略1：
	//			当速度大于平飞速度时----拉杆将动能转为势能进而保持平飞()
	//			当速度小于平飞速度时----顶杆将势能转为动能进而保持平飞
	//		策略2：
	//			当速度大于平飞速度时----顶杆保持高度不变(能耗损大)
	//			当速度小于平飞速度时----加大油门并通过拉杆保持高度不变最终达到平飞速度减小油门
	int altitude = (((int)input->m_AircraftMoveInfo.m_dSelfAlt / 1000)%2 == 0)?((int)input->m_AircraftMoveInfo.m_dSelfAlt)-1: (int)input->m_AircraftMoveInfo.m_dSelfAlt;
	if (altitude == 0)
		altitude = 1;
	else if (altitude > 15)
		altitude = 15;
	int minVeloc = m_data.MinLevelVeloc(altitude),
		maxVeloc = m_data.MaxLevelVeloc(altitude);
	//平飞俯仰范围选择保护[-PITCH_LIMIT,PITCH_LIMIT]:范围外立刻回退纵杆至0
	switch (strategy)
	{
	case KeepEnergy:
		m_output.m_FlyCtrlCmd.m_fThrottle = 0;
		//置油门为0，俯冲获得加速、拉起获得减速;按照0.1的梯度；当速度处于平飞内开始逐渐将飞机保持平稳(平稳以公角更合适)
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
			//势动能转换完成---开始平稳飞机
			JustifyPose(input);
		}
		break;

	case KeepAlt:break;
	}
	return m_output;
}

AIPilotOutput FlightStrategyClass::Track(const AIPilotInput * input)
{
	//设计思路：尽量将速度方向和位移处于同一方向
	//只考虑雷达探测到的目标
	//根据目标三向速度和三向加速度获取到本机最佳控制参数
	//方位角：逆时针为正
	//俯仰角：抬头为正
	//条件1：目标丢失采用平稳飞行策略
	//条件2：目标未丢失，调整飞机俯仰角和侧滑角至与敌机同向,逐步增加油门
	int northVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVN - input->m_AircraftMoveInfo.m_fAccN,
		upVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVU - input->m_AircraftMoveInfo.m_fAccU,
		earthVeloc = input->m_RadarInfo.m_TgtInfo->m_fTgtVE - input->m_AircraftMoveInfo.m_fAccE;
	if (input->m_RadarInfo.m_uiTgtNum > 0)
	{
		//调整飞机姿态至相同姿态
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
		//根据三向速度增加对应角度
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
	//计算2：通过纵杆改变本机俯仰角来靠近目标方位角
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
	//攻角变化（俯仰角）
	m_output.m_FlyCtrlCmd.m_fStickLon = m_data.StickLon(input->m_AircraftMoveInfo.m_fPitch);
	//侧滑角变化
	m_output.m_FlyCtrlCmd.m_fRudder = m_data.StickRudder(input->m_AircraftMoveInfo.m_fYaw);
	//翻转角变化
	m_output.m_FlyCtrlCmd.m_fStickLat = m_data.StickLat(input->m_AircraftMoveInfo.m_fRoll);
	//油门变化
	LevelThrottle(input);
	return m_output;
}
