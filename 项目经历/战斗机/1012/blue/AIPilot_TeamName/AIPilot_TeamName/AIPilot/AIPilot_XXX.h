#pragma once

#include "aipilot.h"
#include <Winsock2.h>
#include <fstream>
#include <iostream>
#include <io.h>

#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)

#define MAX_TGT_NUM 8
#define MAX_MRAAM_NUM 6				
#define MAX_SRAAM_NUM 6				
#define MAX_AAM_NUM_IN_SCENE 12	
#define PI 3.1415926f

struct Message
{
	// m_AircraftBasicInfo
	float m_ID;
	float m_lTimeStamp;
	float m_bAlive;
	float m_fFuel;

	// m_AircraftMoveInfo
	float m_dSelfLon;
	float m_dSelfLat;
	float m_dSelfAlt;
	float m_fVN;
	float m_fVU;
	float m_fVE;
	float m_fAccN;
	float m_fAccU;
	float m_fAccE;
	float m_fAccBX;
	float m_fAccBY;
	float m_fAccBZ;
	float m_fTASpeed;
	float m_fMach;
	float 			m_fNormalAccel;
	float 			m_fYaw;
	float			m_fPitch;		
	float			m_fRoll;		
	float			m_fAlpha;		
	float			m_fBeta;		
	float			m_fCrab;		
	float			m_fOmegaYaw;	
	float			m_fOmegaPitch;	
	float			m_fOmegaRoll;	

	// m_RadarInfo
	float			m_eRadarWorkMode;		
	float			m_fAziScanRange;		
	float			m_fEleScanRange;		
	float			m_fAziScanCent;			
	float			m_fEleScanCent;			
	float			m_uiTgtNum;				
	float 			m_TgtInfo[MAX_TGT_NUM][11];	

	// m_HMDInfo
	float			m_uiTgtNum2;				// 光电头瞄探测到的目标数量
	float			m_TgtInfo2[MAX_TGT_NUM][14];	// 光电头瞄探测到的各个目标的信息

	// m_FCInfo
	float	m_eAircraftMainState;	// 飞机系统当前主模式
	float	m_fRmax;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的最大攻击距离
	float	m_fRnoescape;	// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的不可逃逸攻击距离
	float	m_fRmin;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，导弹对当前目标的最小攻击距离，低于该距离时，导弹不能发射
	float	m_bINRNG;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，目标是否进入导弹最大攻击距离的标志量
	float	m_bSHOOT;		// 本机和目标在当前高度速度及进入角条件下，采取平飞姿态时，目标是否进入导弹不可逃逸攻击距离的标志量
	float	m_bWeaponReady;	// 当前是否有武器准备好可以发射。当处于中距条件下时，判断是否有中距弹准备好；当处于近距条件下时，判断是否有近距弹准备好

	// m_ESMInfo
	float	m_uiAlarmTgtNum;						// 当前电子战告警目标数量
	float	m_AlarmTgtInfo[MAX_TGT_NUM][5];			// 各个告警目标的信息

	// m_DASInfo
	float				m_uiThreatTgtNum;						// 当前DAS告警目标数量
	float				m_ThreatTgtInfo[MAX_TGT_NUM][3];			// 各个DAS告警目标的信息

	// m_AWACSInfo
	float			m_uiTgtNum3;						// 当前外部预警信息中包含的目标数量
	float			m_TgtInfo3[MAX_TGT_NUM][8];		// 各个目标的信息

	// m_MRAAMDataMsgSet
	float			m_uiMsgNum;					// 回传信息数量
	float		 	m_MRAAMDataMsg[MAX_MRAAM_NUM][9];

	// m_AAMDataSet
	float		m_iAAMNum;					// 空空导弹数量
	float		m_AAMData[MAX_AAM_NUM_IN_SCENE][15];
};


class AIPilot_TeamName :
	public AIPilot
{
public:
	AIPilot_TeamName(void);
	~AIPilot_TeamName(void);

public:
	
	bool Init(void* pInitData, unsigned short index);

	bool Step();

	bool Delete();

	bool IsUpdate();

	void* getInput();

	void* getOutput();

	void serialize();

	void write2acmi();

public:
	AIPilotInput	m_Input;

	AIPilotOutput	m_Output;

	Message message;

	SOCKET sockClient;

	std::ofstream fout;

	// 红蓝方标志
	Enum_AircraftIff m_eIFF;
};
