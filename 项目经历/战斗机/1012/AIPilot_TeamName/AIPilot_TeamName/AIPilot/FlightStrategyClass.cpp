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
	int minVeloc = m_data.MinLevelVeloc(input->m_AircraftMoveInfo.m_dSelfAlt),
		maxVeloc = m_data.MaxLevelVeloc(input->m_AircraftMoveInfo.m_dSelfAlt);
	//平飞俯仰范围选择保护[-PITCH_LIMIT,PITCH_LIMIT]:范围外立刻回退纵杆至0
	switch (strategy)
	{
	case KeepEnergy:
		m_output.m_FlyCtrlCmd.m_fThrottle = 0;
		//置油门为0，俯冲获得加速、拉起获得减速;按照0.1的梯度；当速度处于平飞内开始逐渐将飞机保持平稳(平稳以公角更合适)
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
			//势动能转换完成---开始平稳飞机
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
	//设计思路：尽量将速度方向和位移处于同一方向
	//只考虑雷达探测到的目标
	//根据目标方位角、俯仰角、三向速度和三向加速度获取到本机最佳控制参数
	//方位角：逆时针为正
	//俯仰角：抬头为正
	bool azis = false, aEle = false;
	//条件1：目标丢失采用平稳飞行策略
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
	//计算2：通过纵杆改变本机俯仰角来靠近目标方位角
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
	//攻角变化
	if (input->m_AircraftMoveInfo.m_fAlpha > ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fStickLon = -GRADS;
	else if(input->m_AircraftMoveInfo.m_fAlpha < -ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fStickLon = GRADS;
	else
		m_output.m_FlyCtrlCmd.m_fStickLon = 0;
	//侧滑角变化
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
	//油门变化
	if (input->m_AircraftMoveInfo.m_fAccU < -ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fThrottle += GRADS;
	else if (input->m_AircraftMoveInfo.m_fAccU > ERRORRANGE)
		m_output.m_FlyCtrlCmd.m_fThrottle -= GRADS;
}
