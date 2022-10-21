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
	//设计思路：尽量将速度方向和位移处于同一方向
	//只考虑雷达探测到的目标
	//根据目标方位角、俯仰角、三向速度和三向加速度获取到本机最佳控制参数
	//方位角：逆时针为正
	//俯仰角：抬头为正
	//条件1：目标不丢失的本机的信息区间值【方位角俯仰角相同，方位角俯仰角处于雷达可探测边缘】

	//计算1：通过脚蹬改变本机偏航角来靠近目标方位角
	input->m_RadarInfo.m_TgtInfo->m_fTgtAzi
	//计算2：通过纵杆改变本机俯仰角来靠近目标方位角
	return nullptr;
}
