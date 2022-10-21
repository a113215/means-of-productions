#ifndef __AI_INTERFACE_H__
#define __AI_INTERFACE_H__

//----------------------------------------------- 常量定义 -----------------------------------------------

#define MAX_TGT_NUM 8
#define MAX_MRAAM_NUM 6				// 单机允许挂载的最大中距空空导弹数量
#define MAX_SRAAM_NUM 6				// 单机允许挂载的最大近距空空导弹数量
#define MAX_AAM_NUM_IN_SCENE 12		// 仿真场景中允许的最大空空导弹数量


//--------------------------------------------- 数据结构定义 ---------------------------------------------

// 仿真飞机实体向算法模块发送的本机基本状态信息
struct SAircraftBasicInfo_AI_Interface
{
	unsigned short	m_ID;			// 本机ID

	unsigned long	m_lTimeStamp;	// 时标（仿真开始时刻为0，单位：毫秒）

	bool			m_bAlive;		// 存活状态（飞机存活时为true，否则为false）

	float			m_fFuel;		// 剩余燃油（单位：千克）

	SAircraftBasicInfo_AI_Interface()
	{
		m_ID			= 0;
		m_lTimeStamp	= 0;
		m_bAlive		= true;
		m_fFuel			= 0;
	}

	SAircraftBasicInfo_AI_Interface &operator = (const SAircraftBasicInfo_AI_Interface &_info)
	{
		m_ID			= _info.m_ID;
		m_lTimeStamp	= _info.m_lTimeStamp;
		m_bAlive		= _info.m_bAlive;
		m_fFuel			= _info.m_fFuel;
		return *this;
	}
};

// 仿真飞机实体向算法模块发送的本机运动状态信息
struct SAircraftMoveInfo_AI_Interface
{
	double			m_dSelfLon;		// 本机经度（东经为正，西经为负，单位：度）

	double			m_dSelfLat;		// 本机纬度（北纬为正，南纬为负，单位：度）

	double			m_dSelfAlt;		// 本机高度（海拔高度，单位：米）

	float			m_fVN;			// 本机北向速度（向北为正，以当前飞机质心为原点，单位：米/秒）

	float			m_fVU;			// 本机天向速度（向上为正，以当前飞机质心为原点，单位：米/秒）

	float			m_fVE;			// 本机东向速度（向东为正，以当前飞机质心为原点，单位：米/秒）

	float			m_fAccN;		// 本机北向加速度（向北为正，以当前飞机质心为原点，单位：米/秒2）

	float			m_fAccU;		// 本机天向加速度（向上为正，以当前飞机质心为原点，单位：米/秒2）

	float			m_fAccE;		// 本机东向加速度（向东为正，以当前飞机质心为原点，单位：米/秒2）

	float			m_fAccBX;		// 本机机体系X轴向加速度（以当前飞机质心为原点，单位：米/秒2）

	float			m_fAccBY;		// 本机机体系Y轴向加速度（以当前飞机质心为原点，单位：米/秒2）

	float			m_fAccBZ;		// 本机机体系Z轴向加速度（以当前飞机质心为原点，单位：米/秒2）

	float			m_fTASpeed;		// 本机真空速（单位：米/秒）

	float			m_fMach;		// 本机马赫数（单位：马赫）

	float			m_fNormalAccel;	// 本机法向过载（单位：G）

	float			m_fYaw;			// 本机偏航角（正北为0，逆时针旋转为正，单位：弧度）

	float			m_fPitch;		// 本机俯仰角（飞机平飞时为0，抬头为正，单位：弧度）

	float			m_fRoll;		// 本机滚转角（飞机平飞时为0，右滚转为正，单位：弧度）

	float			m_fAlpha;		// 本机攻角（机头高于气流方向时为正，单位：弧度）

	float			m_fBeta;		// 本机侧滑角（机头偏于气流右侧时为正，单位：弧度）

	float			m_fCrab;		// 本机偏流角（单位：弧度）

	float			m_fOmegaYaw;	// 本机偏航角速度（逆时针旋转为正，单位：弧度/秒）

	float			m_fOmegaPitch;	// 本机俯仰角速度（飞机抬头时为正，单位：弧度/秒）

	float			m_fOmegaRoll;	// 本机滚转角速度（飞机向右滚转时为正，单位：弧度/秒）

	SAircraftMoveInfo_AI_Interface()
	{
		m_dSelfLon		= 0;		// 本机经度（东经为正，西经为负，单位：度）
		m_dSelfLat		= 0;		// 本机纬度（北纬为正，南纬为负，单位：度）
		m_dSelfAlt		= 0;		// 本机高度（海拔高度，单位：米）
		m_fVN			= 0;		// 本机北向速度（向北为正，以当前飞机质心为原点，单位：米/秒）
		m_fVU			= 0;		// 本机天向速度（向上为正，以当前飞机质心为原点，单位：米/秒）
		m_fVE			= 0;		// 本机东向速度（向东为正，以当前飞机质心为原点，单位：米/秒）
		m_fAccN			= 0;		// 本机北向加速度（向北为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccU			= 0;		// 本机天向加速度（向上为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccE			= 0;		// 本机东向加速度（向东为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccBX		= 0;		// 本机机体系X轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fAccBY		= 0;		// 本机机体系Y轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fAccBZ		= 0;		// 本机机体系Z轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fTASpeed		= 0;		// 本机真空速（单位：米/秒）
		m_fMach			= 0;		// 本机马赫数（单位：马赫）
		m_fNormalAccel	= 0;		// 本机法向过载（单位：G）
		m_fYaw			= 0;		// 本机偏航角（正北为0，逆时针旋转为正，单位：弧度）
		m_fPitch		= 0;		// 本机俯仰角（飞机平飞时为0，抬头为正，单位：弧度）
		m_fRoll			= 0;		// 本机滚转角（飞机平飞时为0，右滚转为正，单位：弧度）
		m_fAlpha		= 0;		// 本机攻角（机头高于气流方向时为正，单位：弧度）
		m_fBeta			= 0;		// 本机侧滑角（机头偏于气流右侧时为正，单位：弧度）
		m_fCrab			= 0;		// 本机偏流角（单位：弧度）
		m_fOmegaYaw		= 0;		// 本机偏航角速度（逆时针旋转为正，单位：弧度/秒）
		m_fOmegaPitch	= 0;		// 本机俯仰角速度（飞机抬头时为正，单位：弧度/秒）
		m_fOmegaRoll	= 0;		// 本机滚转角速度（飞机向右滚转时为正，单位：弧度/秒）
	}

	SAircraftMoveInfo_AI_Interface &operator = (const SAircraftMoveInfo_AI_Interface &_info)
	{
		m_dSelfLon		= _info.m_dSelfLon;		// 本机经度（东经为正，西经为负，单位：度）
		m_dSelfLat		= _info.m_dSelfLat;		// 本机纬度（北纬为正，南纬为负，单位：度）
		m_dSelfAlt		= _info.m_dSelfAlt;		// 本机高度（海拔高度，单位：米）
		m_fVN			= _info.m_fVN;			// 本机北向速度（向北为正，以当前飞机质心为原点，单位：米/秒）
		m_fVU			= _info.m_fVU;			// 本机天向速度（向上为正，以当前飞机质心为原点，单位：米/秒）
		m_fVE			= _info.m_fVE;			// 本机东向速度（向东为正，以当前飞机质心为原点，单位：米/秒）
		m_fAccN			= _info.m_fAccN;		// 本机北向加速度（向北为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccU			= _info.m_fAccU;		// 本机天向加速度（向上为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccE			= _info.m_fAccE;		// 本机东向加速度（向东为正，以当前飞机质心为原点，单位：米/秒2）
		m_fAccBX		= _info.m_fAccBX;		// 本机机体系X轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fAccBY		= _info.m_fAccBY;		// 本机机体系Y轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fAccBZ		= _info.m_fAccBZ;		// 本机机体系Z轴向加速度（以当前飞机质心为原点，单位：米/秒2）
		m_fTASpeed		= _info.m_fTASpeed;		// 本机真空速（单位：米/秒）
		m_fMach			= _info.m_fMach;		// 本机马赫数（单位：马赫）
		m_fNormalAccel	= _info.m_fNormalAccel;	// 本机法向过载（单位：G）
		m_fYaw			= _info.m_fYaw;			// 本机偏航角（正北为0，逆时针旋转为正，单位：弧度）
		m_fPitch		= _info.m_fPitch;		// 本机俯仰角（飞机平飞时为0，抬头为正，单位：弧度）
		m_fRoll			= _info.m_fRoll;		// 本机滚转角（飞机平飞时为0，右滚转为正，单位：弧度）
		m_fAlpha		= _info.m_fAlpha;		// 本机攻角（机头高于气流方向时为正，单位：弧度）
		m_fBeta			= _info.m_fBeta;		// 本机侧滑角（机头偏于气流右侧时为正，单位：弧度）
		m_fCrab			= _info.m_fCrab;		// 本机偏流角（单位：弧度）
		m_fOmegaYaw		= _info.m_fOmegaYaw;	// 本机偏航角速度（逆时针旋转为正，单位：弧度/秒）
		m_fOmegaPitch	= _info.m_fOmegaPitch;	// 本机俯仰角速度（飞机抬头时为正，单位：弧度/秒）
		m_fOmegaRoll	= _info.m_fOmegaRoll;	// 本机滚转角速度（飞机向右滚转时为正，单位：弧度/秒）
		return *this;
	}
};

// 仿真飞机实体机载火控雷达探测到的单个目标的信息
struct SRadarTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;				// 目标批号

	float			m_fTgtDis;				// 目标距离（雷达探测到的目标与本机的距离，单位：米）

	float			m_fTgtAzi;				// 目标方位角，雷达工作在超视距模式下时，该角度为安稳系下的方位角，在视距内模式下时，为机体系下的方位角，单位：弧度

	float			m_fTgtEle;				// 目标俯仰角，雷达工作在超视距模式下时，该角度为安稳系下的俯仰角，在视距内模式下时，为机体系下的俯仰角，单位：弧度

	float			m_fTgtVN;				// 目标的北向速度，单位：米/秒

	float			m_fTgtVU;				// 目标的天向速度，单位：米/秒

	float			m_fTgtVE;				// 目标的东向速度，单位：米/秒

	float			m_fTgtAccN;				// 目标的北向加速度，单位：米/秒2

	float			m_fTgtAccU;				// 目标的天向加速度，单位：米/秒2

	float			m_fTgtAccE;				// 目标的东向加速度，单位：米/秒2

	float			m_fTgtDisDot;			// 目标的径向速度，单位：米/秒

	SRadarTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;					// 目标批号
		m_fTgtDis	= 0;					// 目标距离（雷达探测到的目标与本机的距离，单位：米）
		m_fTgtAzi	= 0;					// 目标方位角，雷达工作在超视距模式下时，该角度为安稳系下的方位角，在视距内模式下时，为机体系下的方位角，单位：弧度
		m_fTgtEle	= 0;					// 目标俯仰角，雷达工作在超视距模式下时，该角度为安稳系下的俯仰角，在视距内模式下时，为机体系下的俯仰角，单位：弧度
		m_fTgtVN	= 0;					// 目标的北向速度，单位：米/秒
		m_fTgtVU	= 0;					// 目标的天向速度，单位：米/秒
		m_fTgtVE	= 0;					// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= 0;					// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= 0;					// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= 0;					// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= 0;					// 目标的径向速度，单位：米/秒
	}

	SRadarTgtInfo_AI_Interface &operator = (const SRadarTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;		// 目标批号
		m_fTgtDis	= _info.m_fTgtDis;		// 目标距离（雷达探测到的目标与本机的距离，单位：米）
		m_fTgtAzi	= _info.m_fTgtAzi;		// 目标方位角，雷达工作在超视距模式下时，该角度为安稳系下的方位角，在视距内模式下时，为机体系下的方位角，单位：弧度
		m_fTgtEle	= _info.m_fTgtEle;		// 目标俯仰角，雷达工作在超视距模式下时，该角度为安稳系下的俯仰角，在视距内模式下时，为机体系下的俯仰角，单位：弧度
		m_fTgtVN	= _info.m_fTgtVN;		// 目标的北向速度，单位：米/秒
		m_fTgtVU	= _info.m_fTgtVU;		// 目标的天向速度，单位：米/秒
		m_fTgtVE	= _info.m_fTgtVE;		// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= _info.m_fTgtAccN;		// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= _info.m_fTgtAccU;		// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= _info.m_fTgtAccE;		// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= _info.m_fTgtDisDot;	// 目标的径向速度，单位：米/秒
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;					// 目标批号
		m_fTgtDis	= 0;					// 目标距离（雷达探测到的目标与本机的距离，单位：米）
		m_fTgtAzi	= 0;					// 目标方位角，雷达工作在超视距模式下时，该角度为安稳系下的方位角，在视距内模式下时，为机体系下的方位角，单位：弧度
		m_fTgtEle	= 0;					// 目标俯仰角，雷达工作在超视距模式下时，该角度为安稳系下的俯仰角，在视距内模式下时，为机体系下的俯仰角，单位：弧度
		m_fTgtVN	= 0;					// 目标的北向速度，单位：米/秒
		m_fTgtVU	= 0;					// 目标的天向速度，单位：米/秒
		m_fTgtVE	= 0;					// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= 0;					// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= 0;					// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= 0;					// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= 0;					// 目标的径向速度，单位：米/秒
	}
};

// 雷达工作模式定义
enum Enum_RadarWorkMode
{
	Enum_RadarWorkMode_OFF = 0,						// 关机

	Enum_RadarWorkMode_BVR = 1,						// 超视距模式

	Enum_RadarWorkMode_WVR = 2						// 视距内模式
};

// 仿真飞机实体向算法模块发送的本机机载火控雷达获取的目标信息
struct SRadarInfo_AI_Interface
{
	Enum_RadarWorkMode			m_eRadarWorkMode;		// 雷达工作模式

	float						m_fAziScanRange;		// 雷达扫描方位范围（单位：弧度，超视距模式下为30度、60度、120度中的一个，视距内模式下始终为10度）

	float						m_fEleScanRange;		// 雷达扫描俯仰范围（单位：弧度，超视距模式下为4.5度一行，视距内模式下固定为60度[-7度，53度]）

	float						m_fAziScanCent;			// 雷达扫描方位中心（单位：弧度，该值仅在超视距模式下可调，且为安稳系下的角度，视距内模式下始终为0）

	float						m_fEleScanCent;			// 雷达扫描俯仰中心（单位：弧度，该值仅在超视距模式下可调，且为安稳系下的角度，视距内模式下始终为0）

	unsigned short				m_uiTgtNum;				// 雷达探测到的目标数量

	SRadarTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];	// 雷达探测到的各个目标的信息

	SRadarInfo_AI_Interface()
	{
		m_eRadarWorkMode = Enum_RadarWorkMode_OFF;
		m_fAziScanRange = 0;
		m_fEleScanRange = 0;
		m_fAziScanCent = 0;
		m_fEleScanCent = 0;
		m_uiTgtNum = 0;
	}

	void clear()
	{
		m_eRadarWorkMode = Enum_RadarWorkMode_OFF;
		m_fAziScanRange = 0;
		m_fEleScanRange = 0;
		m_fAziScanCent = 0;
		m_fEleScanCent = 0;
		m_uiTgtNum = 0;
		for (int i=0; i<MAX_TGT_NUM; i++)
		{
			m_TgtInfo[i].clear();
		}
	}
};

// 仿真飞机实体光电头瞄探测到的单个目标信息
struct SHMDTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;				// 目标批号（对于每一个目标均有唯一批号）

	float			m_fTgtDis;				// 目标距离（光电头瞄探测到的目标与本机的距离，单位：米）

	float			m_fTgtAziC;				// 目标在本机机体系下的方位角，单位：弧度

	float			m_fTgtEleC;				// 目标在本机机体系下的俯仰角，单位：弧度

	float			m_fYaw;					// 目标的航向角，单位：弧度

	float			m_fPitch;				// 目标的俯仰角，单位：弧度

	float			m_fRoll;				// 目标的滚转角，单位：弧度

	float			m_fTgtVN;				// 目标的北向速度，单位：米/秒

	float			m_fTgtVU;				// 目标的天向速度，单位：米/秒

	float			m_fTgtVE;				// 目标的东向速度，单位：米/秒

	float			m_fTgtAccN;				// 目标的北向加速度，单位：米/秒2

	float			m_fTgtAccU;				// 目标的天向加速度，单位：米/秒2

	float			m_fTgtAccE;				// 目标的东向加速度，单位：米/秒2

	float			m_fTgtDisDot;			// 目标的径向速度，单位：米/秒

	SHMDTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;					// 目标批号
		m_fTgtDis	= 0;					// 目标距离（光电头瞄探测到的目标与本机的距离，单位：米）
		m_fTgtAziC	= 0;					// 目标在本机机体系下的方位角，该角度在视距内模式下输出，单位：弧度
		m_fTgtEleC	= 0;					// 目标在本机机体系下的俯仰角，该角度在视距内模式下输出，单位：弧度
		m_fYaw		= 0;					// 目标的航向角，单位：弧度
		m_fPitch	= 0;					// 目标的俯仰角，单位：弧度
		m_fRoll		= 0;					// 目标的滚转角，单位：弧度
		m_fTgtVN	= 0;					// 目标的北向速度，单位：米/秒
		m_fTgtVU	= 0;					// 目标的天向速度，单位：米/秒
		m_fTgtVE	= 0;					// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= 0;					// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= 0;					// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= 0;					// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= 0;					// 目标的径向速度，单位：米/秒
	}

	SHMDTgtInfo_AI_Interface &operator = (const SHMDTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;		// 目标批号
		m_fTgtDis	= _info.m_fTgtDis;		// 目标距离（光电头瞄探测到的目标与本机的距离，单位：米）
		m_fTgtAziC	= _info.m_fTgtAziC;		// 目标在本机机体系下的方位角，单位：弧度
		m_fTgtEleC	= _info.m_fTgtEleC;		// 目标在本机机体系下的俯仰角，单位：弧度
		m_fYaw		= _info.m_fYaw;			// 目标的航向角，单位：弧度
		m_fPitch	= _info.m_fPitch;		// 目标的俯仰角，单位：弧度
		m_fRoll		= _info.m_fRoll;		// 目标的滚转角，单位：弧度
		m_fTgtVN	= _info.m_fTgtVN;		// 目标的北向速度，单位：米/秒
		m_fTgtVU	= _info.m_fTgtVU;		// 目标的天向速度，单位：米/秒
		m_fTgtVE	= _info.m_fTgtVE;		// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= _info.m_fTgtAccN;		// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= _info.m_fTgtAccU;		// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= _info.m_fTgtAccE;		// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= _info.m_fTgtDisDot;	// 目标的径向速度，单位：米/秒
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;					// 目标批号
		m_fTgtDis	= 0;					// 目标距离（光电头瞄探测到的目标与本机的距离，单位：米）
		m_fTgtAziC	= 0;					// 目标在本机机体系下的方位角，该角度在视距内模式下输出，单位：弧度
		m_fTgtEleC	= 0;					// 目标在本机机体系下的俯仰角，该角度在视距内模式下输出，单位：弧度
		m_fYaw		= 0;					// 目标的航向角，单位：弧度
		m_fPitch	= 0;					// 目标的俯仰角，单位：弧度
		m_fRoll		= 0;					// 目标的滚转角，单位：弧度
		m_fTgtVN	= 0;					// 目标的北向速度，单位：米/秒
		m_fTgtVU	= 0;					// 目标的天向速度，单位：米/秒
		m_fTgtVE	= 0;					// 目标的东向速度，单位：米/秒
		m_fTgtAccN	= 0;					// 目标的北向加速度，单位：米/秒2
		m_fTgtAccU	= 0;					// 目标的天向加速度，单位：米/秒2
		m_fTgtAccE	= 0;					// 目标的东向加速度，单位：米/秒2
		m_fTgtDisDot= 0;					// 目标的径向速度，单位：米/秒
	}
};

// 仿真飞机实体向算法模块发送的本机光电头瞄获取的目标信息
struct SHMDInfo_AI_Interface
{
	unsigned short				m_uiTgtNum;				// 光电头瞄探测到的目标数量

	SHMDTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];	// 光电头瞄探测到的各个目标的信息

	SHMDInfo_AI_Interface()
	{
		m_uiTgtNum = 0;
	}

	void clear()
	{
		m_uiTgtNum	= 0;
		for (int i=0; i<MAX_TGT_NUM; i++)
		{
			m_TgtInfo[i].clear();
		}
	}
};

// 飞机系统任务模式定义
enum Enum_AircraftTaskMode
{
	Enum_AircraftTaskMode_BVR = 0,					// 超视距
	Enum_AircraftTaskMode_WVR = 1,					// 视距内
};

// 仿真飞机实体向算法模块发送的本机火控输出信息
struct SFCInfo_AI_Interface
{
	Enum_AircraftTaskMode m_eAircraftMainState;	// 飞机系统当前主模式

	float	m_fRmax;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的最大攻击距离

	float	m_fRnoescape;	// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的不可逃逸攻击距离

	float	m_fRmin;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的最小攻击距离，低于该距离时，导弹不能发射

	bool	m_bINRNG;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，目标是否进入导弹最大攻击距离的标志量

	bool	m_bSHOOT;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，目标是否进入导弹不可逃逸攻击距离的标志量

	bool	m_bWeaponReady;	// 当前是否有武器准备好可以发射。当处于中距条件下时，判断是否有中距弹准备好；当处于近距条件下时，判断是否有近距弹准备好

	SFCInfo_AI_Interface()
	{
		m_eAircraftMainState = Enum_AircraftTaskMode_BVR;
		m_fRmax			= 0.0f;
		m_fRnoescape	= 0.0f;
		m_fRmin			= 0.0f;
		m_bINRNG		= false;
		m_bSHOOT		= false;
		m_bWeaponReady	= false;
	}

	SFCInfo_AI_Interface &operator = (const SFCInfo_AI_Interface &_info)
	{
		m_eAircraftMainState = _info.m_eAircraftMainState;
		m_fRmax			= _info.m_fRmax;
		m_fRnoescape	= _info.m_fRnoescape;
		m_fRmin			= _info.m_fRmin;
		m_bINRNG		= _info.m_bINRNG;
		m_bSHOOT		= _info.m_bSHOOT;
		m_bWeaponReady	= _info.m_bWeaponReady;
		return *this;
	}

	void clear()
	{
		m_eAircraftMainState = Enum_AircraftTaskMode_BVR;
		m_fRmax			= 0.0f;
		m_fRnoescape	= 0.0f;
		m_fRmin			= 0.0f;
		m_bINRNG		= false;
		m_bSHOOT		= false;
		m_bWeaponReady	= false;
	}
};

// 电子战告警目标类型定义
enum Enum_ESMTgtType
{	
	Enum_ESMTgtType_Invalid = 0,						// 未知
	Enum_ESMTgtType_Missile = 1,						// 导弹	
	Enum_ESMTgtType_Plane	= 2							// 飞机	 
};

// 电子战告警目标敌我识别属性
enum Enum_ESMTgtIff
{
	Enum_ESMTgtIff_Friend	= 0,						// 友
	Enum_ESMTgtIff_Unknown	= 1,						// 不明
	Enum_ESMTgtIff_Foe		= 2							// 敌
};

// 仿真飞机实体向算法模块发送的单个电子战告警目标信息
struct SESMTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;		// 告警目标批号（每个告警目标均有唯一批号）

	Enum_ESMTgtType	m_eTgtType;		// 告警目标类型（对于飞机火控雷达的告警，类型为“飞机”；对于导弹导引头的告警，类型为“导弹”）

	Enum_ESMTgtIff	m_eTgtIff;		// 告警目标敌我识别属性

	float			m_fTgtAzi;		// 告警目标在本机机体系下的方位角（单位：弧度）

	float			m_fTgtEle;		// 告警目标在本机机体系下的俯仰角（单位：弧度）

	SESMTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;
		m_eTgtType	= Enum_ESMTgtType_Invalid;
		m_eTgtIff	= Enum_ESMTgtIff_Unknown;
		m_fTgtAzi	= 0.0f;
		m_fTgtEle	= 0.0f;
	}

	SESMTgtInfo_AI_Interface &operator = (const SESMTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;
		m_eTgtType	= _info.m_eTgtType;
		m_eTgtIff	= _info.m_eTgtIff;
		m_fTgtAzi	= _info.m_fTgtAzi;
		m_fTgtEle	= _info.m_fTgtEle;
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;
		m_eTgtType	= Enum_ESMTgtType_Invalid;
		m_eTgtIff	= Enum_ESMTgtIff_Unknown;
		m_fTgtAzi	= 0.0f;
		m_fTgtEle	= 0.0f;
	}

};

// 仿真飞机实体向算法模块发送的电子战告警信息
struct SESMInfo_AI_Interface
{
	unsigned short				m_uiAlarmTgtNum;						// 当前电子战告警目标数量

	SESMTgtInfo_AI_Interface	m_AlarmTgtInfo[MAX_TGT_NUM];			// 各个告警目标的信息

	SESMInfo_AI_Interface()
	{
		m_uiAlarmTgtNum = 0;
	}

	void clear()
	{
		m_uiAlarmTgtNum = 0;
		for (int i=0; i<MAX_TGT_NUM; i++)
		{
			m_AlarmTgtInfo[i].clear();
		}
	}
};

// 仿真飞机实体向算法模块发送的单个DAS告警目标信息
struct SDASTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;		// 告警目标批号（每个告警目标均有唯一批号）

	float			m_fTgtAzi;		// 告警目标在本机机体系下的方位角（单位：弧度）

	float			m_fTgtEle;		// 告警目标在本机机体系下的俯仰角（单位：弧度）

	SDASTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;
		m_fTgtAzi	= 0.0f;
		m_fTgtEle	= 0.0f;
	}

	SDASTgtInfo_AI_Interface &operator = (const SDASTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;
		m_fTgtAzi	= _info.m_fTgtAzi;
		m_fTgtEle	= _info.m_fTgtEle;
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;
		m_fTgtAzi	= 0.0f;
		m_fTgtEle	= 0.0f;
	}
};

// 仿真飞机实体向算法模块发送的DAS告警信息
struct SDASInfo_AI_Interface
{
	unsigned short				m_uiThreatTgtNum;						// 当前DAS告警目标数量

	SDASTgtInfo_AI_Interface	m_ThreatTgtInfo[MAX_TGT_NUM];			// 各个DAS告警目标的信息

	SDASInfo_AI_Interface()
	{
		m_uiThreatTgtNum = 0;
	}

	void clear()
	{
		m_uiThreatTgtNum = 0;
		for (int i=0; i<MAX_TGT_NUM; i++)
		{
			m_ThreatTgtInfo[i].clear();
		}
	}
};

enum Enum_AircraftIff
{
	Enum_AircraftIff_Red	= 0,					// 红方
	Enum_AircraftIff_Blue	= 1,					// 蓝方
	Enum_AircraftIff_White	= 2						// 白方
};

// 仿真飞机实体向算法模块发送的单个外部低频率预警目标信息
struct SAWACSTgtInfo_AI_Interface
{
	unsigned short		m_uiTgtLot;		// 预警目标批号（每个目标均有唯一批号）

	Enum_AircraftIff	m_eIFF;			// 预警目标的敌我识别属性

	float				m_fTgtLon;		// 预警目标经度（东经为正，西经为负，单位：度）

	float				m_fTgtLat;		// 预警目标纬度（北纬为正，南纬为负，单位：度）

	float				m_fTgtAlt;		// 预警目标高度（海拔高度，单位：米）

	float				m_fTgtVN;		// 预警目标的北向速度（单位：米/秒）

	float				m_fTgtVU;		// 预警目标的天向速度（单位：米/秒）

	float				m_fTgtVE;		// 预警目标的东向速度（单位：米/秒）

	SAWACSTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;						// 预警目标批号（每个目标均有唯一批号）
		m_eIFF		= Enum_AircraftIff_White;	// 预警目标的敌我识别属性
		m_fTgtLon	= 0;						// 预警目标经度（东经为正，西经为负，单位：度）
		m_fTgtLat	= 0;						// 预警目标纬度（北纬为正，南纬为负，单位：度）
		m_fTgtAlt	= 0;						// 预警目标高度（海拔高度，单位：米）
		m_fTgtVN	= 0;						// 预警目标的北向速度（单位：米/秒）
		m_fTgtVU	= 0;						// 预警目标的天向速度（单位：米/秒）
		m_fTgtVE	= 0;						// 预警目标的东向速度（单位：米/秒）
	}

	SAWACSTgtInfo_AI_Interface &operator = (const SAWACSTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;			// 预警目标批号（每个目标均有唯一批号）
		m_eIFF		= _info.m_eIFF;				// 预警目标的敌我识别属性
		m_fTgtLon	= _info.m_fTgtLon;			// 预警目标经度（东经为正，西经为负，单位：度）
		m_fTgtLat	= _info.m_fTgtLat;			// 预警目标纬度（北纬为正，南纬为负，单位：度）
		m_fTgtAlt	= _info.m_fTgtAlt;			// 预警目标高度（海拔高度，单位：米）
		m_fTgtVN	= _info.m_fTgtVN;			// 预警目标的北向速度（单位：米/秒）
		m_fTgtVU	= _info.m_fTgtVU;			// 预警目标的天向速度（单位：米/秒）
		m_fTgtVE	= _info.m_fTgtVE;			// 预警目标的东向速度（单位：米/秒）
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;						// 预警目标批号（每个目标均有唯一批号）
		m_eIFF		= Enum_AircraftIff_White;	// 预警目标的敌我识别属性
		m_fTgtLon	= 0;						// 预警目标经度（东经为正，西经为负，单位：度）
		m_fTgtLat	= 0;						// 预警目标纬度（北纬为正，南纬为负，单位：度）
		m_fTgtAlt	= 0;						// 预警目标高度（海拔高度，单位：米）
		m_fTgtVN	= 0;						// 预警目标的北向速度（单位：米/秒）
		m_fTgtVU	= 0;						// 预警目标的天向速度（单位：米/秒）
		m_fTgtVE	= 0;						// 预警目标的东向速度（单位：米/秒）
	}

};

// 仿真飞机实体向算法模块输出的外部低频率预警目标信息
struct SAWACSInfo_AI_Interface
{
	unsigned short			m_uiTgtNum;						// 当前外部预警信息中包含的目标数量

	SAWACSTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];		// 各个目标的信息

	SAWACSInfo_AI_Interface()
	{
		m_uiTgtNum = 0;
	}

	void clear()
	{
		m_uiTgtNum	= 0;
		for (int i=0; i<MAX_TGT_NUM; i++)
		{
			m_TgtInfo[i].clear();
		}
	}
};

// 单枚中距空空导弹的回传信息
struct SMRAAMDataMsg_AI_Interface
{
	unsigned short		m_uiAAMID;				// 中距空空导弹ID

	bool				m_bSeekerOpen;			// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）

	bool				m_bCapture;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）

	double				m_dLon;					// 导弹经度（单位：度）

	double				m_dLat;					// 导弹纬度（单位：度）

	double				m_dAlt;					// 导弹高度（单位：米）

	float				m_fMslVX;				// 导弹北向速度（单位：米/秒）

	float				m_fMslVU;				// 导弹天向速度（单位：米/秒）

	float				m_fMslVE;				// 导弹东向速度（单位：米/秒）

	SMRAAMDataMsg_AI_Interface()
	{
		m_uiAAMID		= 0;					// 中距空空导弹ID
		m_bSeekerOpen	= false;				// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= false;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= 0;					// 导弹经度（单位：度）
		m_dLat			= 0;					// 导弹纬度（单位：度）
		m_dAlt			= 0;					// 导弹高度（单位：米）
		m_fMslVX		= 0;					// 导弹北向速度（单位：米/秒）
		m_fMslVU		= 0;					// 导弹天向速度（单位：米/秒）
		m_fMslVE		= 0;					// 导弹东向速度（单位：米/秒）
	}

	SMRAAMDataMsg_AI_Interface& operator = (const SMRAAMDataMsg_AI_Interface& _msg)
	{
		m_uiAAMID		= _msg.m_uiAAMID;		// 中距空空导弹ID
		m_bSeekerOpen	= _msg.m_bSeekerOpen;	// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= _msg.m_bCapture;		// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= _msg.m_dLon;			// 导弹经度（单位：度）
		m_dLat			= _msg.m_dLat;			// 导弹纬度（单位：度）
		m_dAlt			= _msg.m_dAlt;			// 导弹高度（单位：米）
		m_fMslVX		= _msg.m_fMslVX;		// 导弹北向速度（单位：米/秒）
		m_fMslVU		= _msg.m_fMslVU;		// 导弹天向速度（单位：米/秒）
		m_fMslVE		= _msg.m_fMslVE;		// 导弹东向速度（单位：米/秒）
		return *this;
	}

	void clear()
	{
		m_uiAAMID		= 0;					// 中距空空导弹ID
		m_bSeekerOpen	= false;				// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= false;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= 0;					// 导弹经度（单位：度）
		m_dLat			= 0;					// 导弹纬度（单位：度）
		m_dAlt			= 0;					// 导弹高度（单位：米）
		m_fMslVX		= 0;					// 导弹北向速度（单位：米/秒）
		m_fMslVU		= 0;					// 导弹天向速度（单位：米/秒）
		m_fMslVE		= 0;					// 导弹东向速度（单位：米/秒）
	}
};

// 中距空空导弹回传信息集合
struct SMRAAMDataMsgSet_AI_Interface
{
	unsigned short	m_uiMsgNum;					// 回传信息数量
	SMRAAMDataMsg_AI_Interface m_MRAAMDataMsg[MAX_MRAAM_NUM];

	SMRAAMDataMsgSet_AI_Interface()
	{
		m_uiMsgNum = 0;
	}

	void clear()
	{
		m_uiMsgNum = 0;
		for (int i = 0; i < MAX_MRAAM_NUM; i++)
		{
			m_MRAAMDataMsg[i].clear();
		}
	}
};

// 空空导弹类型定义
enum Enum_AAMType
{
	Enum_AAMType_MRAAM = 0,			// 中距空空导弹
	Enum_AAMType_SRAAM = 1			// 近距空空导弹
};

// 空空导弹状态定义
enum Enum_AAMState
{
	Enum_AAMState_Unfired = 0,		// 导弹未发射
	Enum_AAMState_Flying = 1,		// 导弹飞行中
	Enum_AAMState_Hit = 2,			// 导弹已命中
	Enum_AAMState_Lost = 3			// 导弹已失效
};

// 单枚空空导弹的状态信息
// 备注：该部分内容仅供各参赛队算法调试阶段使用，正式比赛时，该部分数据内容为空值。算法开发时请勿使用该数据。
struct SAAMData_AI_Interface
{
	unsigned short		m_uiAAMID;				// 空空导弹ID

	Enum_AAMType		m_eAAMType;				// 空空导弹类型

	unsigned short		m_uiPlaneID;			// 当前空空所属飞机ID

	Enum_AAMState		m_eAAMState;			// 空空导弹状态

	bool				m_bSeekerOpen;			// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）

	bool				m_bCapture;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）

	double				m_dLon;					// 导弹经度（单位：度）

	double				m_dLat;					// 导弹纬度（单位：度）

	double				m_dAlt;					// 导弹高度（单位：米）

	float				m_fMslVX;				// 导弹北向速度（单位：米/秒）

	float				m_fMslVU;				// 导弹天向速度（单位：米/秒）

	float				m_fMslVE;				// 导弹东向速度（单位：米/秒）

	float				m_fMslYaw;				// 导弹飞行方位角（单位：弧度）

	float				m_fMslPitch;			// 导弹飞行俯仰角（单位：弧度）

	float				m_fTgtDis;				// 弹目距离（单位：米）

	SAAMData_AI_Interface()
	{
		m_uiAAMID		= 0;					// 空空导弹ID
		m_eAAMType		= Enum_AAMType_MRAAM;	// 空空导弹类型
		m_uiPlaneID		= 0;					// 当前空空所属飞机ID
		m_eAAMState		= Enum_AAMState_Unfired;// 空空导弹状态
		m_bSeekerOpen	= false;				// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= false;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= 0;					// 导弹经度（单位：度）
		m_dLat			= 0;					// 导弹纬度（单位：度）
		m_dAlt			= 0;					// 导弹高度（单位：米）
		m_fMslVX		= 0;					// 导弹北向速度（单位：米/秒）
		m_fMslVU		= 0;					// 导弹天向速度（单位：米/秒）
		m_fMslVE		= 0;					// 导弹东向速度（单位：米/秒）
		m_fMslYaw		= 0;					// 导弹飞行方位角（单位：弧度）
		m_fMslPitch		= 0;					// 导弹飞行俯仰角（单位：弧度）
		m_fTgtDis		= 0;					// 弹目距离（单位：米）
	}

	SAAMData_AI_Interface& operator = (const SAAMData_AI_Interface& _msg)
	{
		m_uiAAMID		= _msg.m_uiAAMID;		// 空空导弹ID
		m_eAAMType		= _msg.m_eAAMType;		// 空空导弹类型
		m_uiPlaneID		= _msg.m_uiPlaneID;		// 当前空空所属飞机ID
		m_eAAMState		= _msg.m_eAAMState;		// 空空导弹状态
		m_bSeekerOpen	= _msg.m_bSeekerOpen;	// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= _msg.m_bCapture;		// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= _msg.m_dLon;			// 导弹经度（单位：度）
		m_dLat			= _msg.m_dLat;			// 导弹纬度（单位：度）
		m_dAlt			= _msg.m_dAlt;			// 导弹高度（单位：米）
		m_fMslVX		= _msg.m_fMslVX;		// 导弹北向速度（单位：米/秒）
		m_fMslVU		= _msg.m_fMslVU;		// 导弹天向速度（单位：米/秒）
		m_fMslVE		= _msg.m_fMslVE;		// 导弹东向速度（单位：米/秒）
		m_fMslYaw		= _msg.m_fMslYaw;		// 导弹飞行方位角（单位：弧度）
		m_fMslPitch		= _msg.m_fMslPitch;		// 导弹飞行俯仰角（单位：弧度）
		m_fTgtDis		= _msg.m_fTgtDis;		// 弹目距离（单位：米）
		return *this;
	}

	void clear()
	{
		m_uiAAMID		= 0;					// 空空导弹ID
		m_eAAMType		= Enum_AAMType_MRAAM;	// 空空导弹类型
		m_uiPlaneID		= 0;					// 当前空空所属飞机ID
		m_eAAMState		= Enum_AAMState_Unfired;// 空空导弹状态
		m_bSeekerOpen	= false;				// 导弹导引头开机状态（true：导引头已开机；false：导引头未开机）
		m_bCapture		= false;				// 导弹导引头截获状态（true：导引头已截获；false：导引头未截获）
		m_dLon			= 0;					// 导弹经度（单位：度）
		m_dLat			= 0;					// 导弹纬度（单位：度）
		m_dAlt			= 0;					// 导弹高度（单位：米）
		m_fMslVX		= 0;					// 导弹北向速度（单位：米/秒）
		m_fMslVU		= 0;					// 导弹天向速度（单位：米/秒）
		m_fMslVE		= 0;					// 导弹东向速度（单位：米/秒）
		m_fMslYaw		= 0;					// 导弹飞行方位角（单位：弧度）
		m_fMslPitch		= 0;					// 导弹飞行俯仰角（单位：弧度）
		m_fTgtDis		= 0;					// 弹目距离（单位：米）
	}
};

// 空空导弹集合信息
// 备注：该部分内容仅供各参赛队算法调试阶段使用，正式比赛时，该部分数据内容为空值。算法开发时请勿使用该数据！！！
struct SAAMDataSet_AI_Interface
{
	int	m_iAAMNum;					// 空空导弹数量
	SAAMData_AI_Interface m_AAMData[MAX_AAM_NUM_IN_SCENE];

	SAAMDataSet_AI_Interface()
	{
		m_iAAMNum = 0;
	}

	void clear()
	{
		m_iAAMNum = 0;
		for (int i = 0; i < (MAX_AAM_NUM_IN_SCENE); i++)
		{
			m_AAMData[i].clear();
		}
	}
};

// 算法模块输入接口（即仿真飞机实体向算法模块发送的本机状态及态势数据）
struct AIPilotInput
{
	// 本机基本信息
	SAircraftBasicInfo_AI_Interface	m_AircraftBasicInfo;

	// 本机运动状态信息
	SAircraftMoveInfo_AI_Interface	m_AircraftMoveInfo;

	// 本机雷达探测到的目标信息
	SRadarInfo_AI_Interface			m_RadarInfo;

	// 本机光电头瞄探测到的目标信息
	SHMDInfo_AI_Interface			m_HMDInfo;

	// 本机火控系统输出信息
	SFCInfo_AI_Interface			m_FCInfo;

	// 本机电子战告警信息
	SESMInfo_AI_Interface			m_ESMInfo;

	// 本机DAS告警信息
	SDASInfo_AI_Interface			m_DASInfo;

	// 本机接收到的外部预警信息
	SAWACSInfo_AI_Interface			m_AWACSInfo;

	// 中距空空导弹回传信息
	SMRAAMDataMsgSet_AI_Interface	m_MRAAMDataMsgSet;

	// 空空导弹集合状态信息
	// 备注：该部分内容仅供各参赛队算法调试阶段使用，正式比赛时，该部分数据内容为空值。算法开发时请勿使用该数据。
	SAAMDataSet_AI_Interface		m_AAMDataSet;

	AIPilotInput()
	{

	}
};

// 平台飞行控制指令（算法模块向仿真飞机实体输出）
struct SFlyCtrlCmd_AI_Interface
{
	float	m_fStickLat;			// 横向杆位移，取值范围：[-1,1]

	float	m_fStickLon;			// 纵向杆位移，取值范围：[-1,1]

	float	m_fThrottle;			// 油门杆位移，取值范围：[0,1]

	float	m_fRudder;				// 脚蹬位移，取值范围：[-1,1]

	SFlyCtrlCmd_AI_Interface()
	{
		m_fStickLat	= 0.0f;
		m_fStickLon	= 0.0f;
		m_fThrottle	= 0.0f;
		m_fRudder	= 0.0f;
	}

	SFlyCtrlCmd_AI_Interface &operator = (const SFlyCtrlCmd_AI_Interface &_cmd)
	{
		m_fStickLat	= _cmd.m_fStickLat;
		m_fStickLon	= _cmd.m_fStickLon;
		m_fThrottle	= _cmd.m_fThrottle;
		m_fRudder	= _cmd.m_fRudder;
		return *this;
	}
};

// 火控系统控制指令（算法模块向仿真飞机实体输出）
struct SFCCtrlCmd_AI_Interface
{
	Enum_AircraftTaskMode	m_eMainTaskMode;

	SFCCtrlCmd_AI_Interface()
	{
		m_eMainTaskMode	= Enum_AircraftTaskMode_BVR;
	}

	SFCCtrlCmd_AI_Interface &operator = (const SFCCtrlCmd_AI_Interface &_cmd)
	{
		m_eMainTaskMode	= _cmd.m_eMainTaskMode;
		return *this;
	}
};

// 雷达开关机操作定义
enum Enum_RadarOnOff
{
	Enum_RadarOnOff_OFF = 0,						// 关机
	Enum_RadarOnOff_ON	= 1							// 开机
};

// 雷达扫描行数定义
enum Enum_RadarEleScanLine
{
	Enum_RadarEleScanLine_2	= 2,					// 2行扫描
	Enum_RadarEleScanLine_4	= 4						// 4行扫描
};

// 雷达方位扫描范围定义
enum Enum_RadarAziScanRange
{
	Enum_RadarAziScanRange_30	= 30,				// 30度扫描范围
	Enum_RadarAziScanRange_60	= 60,				// 60度扫描范围
	Enum_RadarAziScanRange_120	= 120				// 120度扫描范围
};

// 机载火控雷达控制指令（算法模块向仿真飞机实体输出）
struct SRadarCtrlCmd_AI_Interface
{
	Enum_RadarOnOff			m_eRadarOnOff;			// 雷达开关机操作

	Enum_RadarEleScanLine	m_eEleScanLine;			// 雷达扫描行数（枚举值，转换为整数后即为扫描行数，单位：行）

	Enum_RadarAziScanRange	m_eAziScanRange;		// 雷达方位扫描范围（枚举值，转换为整数后即为扫描范围的角度数，单位：度）

	float					m_fAziScanCent;			// 雷达扫描方位中心，单位：弧度，其取值范围应满足(fabs(m_fAziScanCent)+fabs(m_eAziScanRange/2))<=(PI/3)

	float					m_fEleScanCent;			// 雷达扫描俯仰中心，单位：弧度，其取值范围应满足(fabs(m_fEleScanCent)+(4.5*D_TO_R*m_eEleScanLine/2))<=(PI/3)

	SRadarCtrlCmd_AI_Interface()
	{
		m_eRadarOnOff = Enum_RadarOnOff_OFF;
		m_eEleScanLine	= Enum_RadarEleScanLine_2;
		m_eAziScanRange	= Enum_RadarAziScanRange_30;
		m_fAziScanCent	= 0;
		m_fEleScanCent	= 0;
	}

	SRadarCtrlCmd_AI_Interface &operator = (const SRadarCtrlCmd_AI_Interface &_cmd)
	{
		m_eRadarOnOff	= _cmd.m_eRadarOnOff;
		m_eEleScanLine	= _cmd.m_eEleScanLine;
		m_eAziScanRange	= _cmd.m_eAziScanRange;
		m_fAziScanCent	= _cmd.m_fAziScanCent;
		m_fEleScanCent	= _cmd.m_fEleScanCent;
		return *this;
	}
};

// 机载武器控制指令（算法模块向仿真飞机实体输出）
struct SWeaponCtrlCmd_AI_Interface
{
	bool	m_bWeaponLaunch;						// 空空导弹发射指令，当火控系统解算满足导弹发射条件时，如果当前发射指令为true，且前一帧发射指令为false，则将发射空空导弹

	SWeaponCtrlCmd_AI_Interface()
	{
		m_bWeaponLaunch	= false;
	}

	SWeaponCtrlCmd_AI_Interface &operator = (const SWeaponCtrlCmd_AI_Interface &_cmd)
	{
		m_bWeaponLaunch	= _cmd.m_bWeaponLaunch;
		return *this;
	}
};

// 算法模块输出接口（即算法模块向飞机实体发送的各类控制指令数据）
struct AIPilotOutput
{
	// 平台飞行控制指令
	SFlyCtrlCmd_AI_Interface	m_FlyCtrlCmd;

	// 火控系统控制指令
	SFCCtrlCmd_AI_Interface		m_FCCtrlCmd;

	// 机载火控雷达控制指令
	SRadarCtrlCmd_AI_Interface	m_RadarCtrlCmd;

	// 机载武器控制指令
	SWeaponCtrlCmd_AI_Interface	m_WeaponCtrlCmd;

	AIPilotOutput()
	{

	}
};

// 算法模块初始化接口
struct AIPilotInit
{
	unsigned short		m_ID;						// 飞机ID，飞机的唯一标识（大于0为有效值）

	Enum_AircraftIff	m_eIFF;						// 敌我识别标志

	double				m_dInitLon;					// 初始位置经度（东经为正，单位：度）

	double				m_dInitLat;					// 初始位置纬度（北纬为正，单位：度）

	double				m_dInitAlt;					// 初始海拔高度（单位：米）

	float				m_fInitVelocity;			// 初始速度（单位：米/秒）

	float				m_fInitYaw;					// 初始航向（正北为0，逆时针旋转为正，单位：弧度）

	float				m_fInitPitch;				// 初始俯仰（平飞为0，抬头为正，单位：弧度）

	float				m_fInitRoll;				// 初始滚转（平飞为0，右坡度为正，单位：弧度）

	unsigned short		m_uiMRAAMNum;				// 初始中距弹数量

	unsigned short		m_uiSRAAMNum;				// 初始近距弹数量

	unsigned short		m_fInitFuel;				// 初始载油量（单位：千克）

	AIPilotInit()
	{
		m_ID			= 0;
		m_eIFF			= Enum_AircraftIff_Red;
		m_dInitLon		= 0;
		m_dInitLat		= 0;
		m_dInitAlt		= 0;
		m_fInitVelocity	= 0.0f;
		m_fInitYaw		= 0.0f;
		m_fInitPitch	= 0.0f;
		m_fInitRoll		= 0.0f;
		m_uiMRAAMNum	= 0;
		m_uiSRAAMNum	= 0;
		m_fInitFuel		= 0;
	}
};

#endif