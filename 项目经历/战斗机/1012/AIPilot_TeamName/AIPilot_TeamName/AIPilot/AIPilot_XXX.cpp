#include "AIPilot_XXX.h"
#include <stdio.h>
#include<windows.h>
//#include <torch/torch.h>
//#include <torch/script.h>

AIPilot_TeamName::AIPilot_TeamName(void)
{

}

AIPilot_TeamName::~AIPilot_TeamName(void)
{
	// 资源释放
	// 关闭socket
	//closesocket(sockClient);
	//WSACleanup();
	// 关闭文件句柄
	fout.close();
}


bool AIPilot_TeamName::Init(void* pInitData, unsigned short index)
{
	// 初始化数据
	AIPilotInit* _pInitData = (AIPilotInit*)pInitData;
	m_eIFF = _pInitData->m_eIFF;

	// 算法初始化部分

	// 初始化socket
	//WORD wVersionRequested;
	//WSADATA wsaData;
	//int err;

	//wVersionRequested = MAKEWORD(1, 1);
	//err = WSAStartup(wVersionRequested, &wsaData);
	//if (err != 0) {
	//	return -1;
	//}

	//if (LOBYTE(wsaData.wVersion) != 1 ||
	//	HIBYTE(wsaData.wVersion) != 1) {
	//	WSACleanup();
	//	return -1;
	//}
	//sockClient = socket(AF_INET, SOCK_STREAM, 0);

	//SOCKADDR_IN addrSrv;
	//addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//addrSrv.sin_family = AF_INET;
	//addrSrv.sin_port = htons(1200);
	//connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 初始化文件读写，输出态势信息到acmi
	// 红方需要进行的信息写入
	if (m_eIFF == Enum_AircraftIff_Red)
	{
		// 防止追加到之前的文件中,若存在display.acmi，则删除
		std::string fileName = "replay/display.acmi";
		if (access(fileName.c_str(), 0) == 0)
			remove(fileName.c_str());
		// 打开文件
		fout.open("replay/display.acmi", std::ios::out | std::ios::app);
		fout << "FileType=text/acmi/tacview\nFileVersion=2.1\n0,ReferenceTime=2011-06-02T05:00:00Z\n";
		fout << "#0 \n";
		fout << _pInitData->m_ID << ",";
		fout.precision(14);
		fout << "T=" << _pInitData->m_dInitLon << "|"
			<< _pInitData->m_dInitLat << "|";
		fout.precision(6);
		fout<< _pInitData->m_dInitAlt << "|"
			<< _pInitData->m_fInitRoll << "|"
			<< _pInitData->m_fInitPitch << "|"
			<< -_pInitData->m_fInitYaw << ",";
		fout << "Type=Air+FixedWing,Name=F-16C bl.50,Color=Red" << std::endl;

	}
	else  //蓝方
	{
		// 打开文件
		fout.open("replay/display.acmi", std::ios::out | std::ios::app);
		fout << _pInitData->m_ID << ", ";
		fout.precision(14);
		fout << "T=" << _pInitData->m_dInitLon << "|"
			<< _pInitData->m_dInitLat << "|";
		fout.precision(6);
		fout << _pInitData->m_dInitAlt << "|"
			<< _pInitData->m_fInitRoll << "|"
			<< _pInitData->m_fInitPitch << "|"
			<< -_pInitData->m_fInitYaw << ",";
		fout << "Type=Air+FixedWing,Name=F-16C bl.50,Color=Blue" << std::endl;
	}

	return true;
}


void AIPilot_TeamName::serialize()
{
	AIPilotInput _rawData = m_Input;

	message.m_ID 			= (float) _rawData.m_AircraftBasicInfo.m_ID;
	message.m_lTimeStamp 	= (float) _rawData.m_AircraftBasicInfo.m_lTimeStamp;
	message.m_bAlive 		= (float) _rawData.m_AircraftBasicInfo.m_bAlive;
	message.m_fFuel	 		= (float) _rawData.m_AircraftBasicInfo.m_fFuel;

	message.m_dSelfLon 		= (float) _rawData.m_AircraftMoveInfo.m_dSelfLon;
	message.m_dSelfLat 		= (float) _rawData.m_AircraftMoveInfo.m_dSelfLat;
	message.m_dSelfAlt		= (float) _rawData.m_AircraftMoveInfo.m_dSelfAlt / 5000;
	message.m_fVN 			= (float) _rawData.m_AircraftMoveInfo.m_fVN / 100;
	message.m_fVU 			= (float) _rawData.m_AircraftMoveInfo.m_fVU / 100;
	message.m_fVE 			= (float) _rawData.m_AircraftMoveInfo.m_fVE / 100;
	message.m_fAccN 		= (float) _rawData.m_AircraftMoveInfo.m_fAccN / 2;
	message.m_fAccU 		= (float) _rawData.m_AircraftMoveInfo.m_fAccU / 2;
	message.m_fAccE 		= (float) _rawData.m_AircraftMoveInfo.m_fAccE / 2;
	message.m_fAccBX 		= (float) _rawData.m_AircraftMoveInfo.m_fAccBX / 20;
	message.m_fAccBY 		= (float) _rawData.m_AircraftMoveInfo.m_fAccBY / 20;
	message.m_fAccBZ 		= (float) _rawData.m_AircraftMoveInfo.m_fAccBZ / 20;
	message.m_fTASpeed 		= (float) _rawData.m_AircraftMoveInfo.m_fTASpeed / 200;
	message.m_fMach 		= (float) _rawData.m_AircraftMoveInfo.m_fMach;
	message.m_fNormalAccel 	= (float) _rawData.m_AircraftMoveInfo.m_fNormalAccel;
	message.m_fYaw 			= (float) _rawData.m_AircraftMoveInfo.m_fYaw;
	message.m_fPitch 		= (float) _rawData.m_AircraftMoveInfo.m_fPitch;
	message.m_fRoll 		= (float) _rawData.m_AircraftMoveInfo.m_fRoll;
	message.m_fAlpha 		= (float) _rawData.m_AircraftMoveInfo.m_fAlpha;
	message.m_fBeta 		= (float) _rawData.m_AircraftMoveInfo.m_fBeta;
	message.m_fCrab 		= (float) _rawData.m_AircraftMoveInfo.m_fCrab;
	message.m_fOmegaYaw 	= (float) _rawData.m_AircraftMoveInfo.m_fOmegaYaw;
	message.m_fOmegaPitch 	= (float) _rawData.m_AircraftMoveInfo.m_fOmegaPitch;
	message.m_fOmegaRoll 	= (float) _rawData.m_AircraftMoveInfo.m_fOmegaRoll;

	message.m_eRadarWorkMode 	= (float) _rawData.m_RadarInfo.m_eRadarWorkMode;
	message.m_fAziScanRange 	= (float) _rawData.m_RadarInfo.m_fAziScanRange;
	message.m_fEleScanRange 	= (float) _rawData.m_RadarInfo.m_fEleScanRange;
	message.m_fAziScanCent 		= (float) _rawData.m_RadarInfo.m_fAziScanCent;
	message.m_fEleScanCent 		= (float) _rawData.m_RadarInfo.m_fEleScanCent;
	message.m_uiTgtNum 			= (float) _rawData.m_RadarInfo.m_uiTgtNum;
	for(int i=0; i<MAX_TGT_NUM; i++)
	{

		message.m_TgtInfo[i][0] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_uiTgtLot;
		message.m_TgtInfo[i][1] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtDis;
		message.m_TgtInfo[i][2] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtAzi;
		message.m_TgtInfo[i][3] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtEle;
		message.m_TgtInfo[i][4] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtVN;
		message.m_TgtInfo[i][5] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtVU;
		message.m_TgtInfo[i][6] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtVE;
		message.m_TgtInfo[i][7] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtAccN;
		message.m_TgtInfo[i][8] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtAccU;
		message.m_TgtInfo[i][9] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtAccE;
		message.m_TgtInfo[i][10] = (float) _rawData.m_RadarInfo.m_TgtInfo[i].m_fTgtDisDot;
	}

	message.m_uiTgtNum2 = (float) _rawData.m_HMDInfo.m_uiTgtNum;
	for(int i=0; i<MAX_TGT_NUM; i++)
	{
		message.m_TgtInfo2[i][0] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_uiTgtLot;
		message.m_TgtInfo2[i][1] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtDis / 3000;
		message.m_TgtInfo2[i][2] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtAziC;
		message.m_TgtInfo2[i][3] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtEleC;
		message.m_TgtInfo2[i][4] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fYaw;
		message.m_TgtInfo2[i][5] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fPitch;
		message.m_TgtInfo2[i][6] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fRoll;
		message.m_TgtInfo2[i][7] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtVN / 100;
		message.m_TgtInfo2[i][8] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtVU / 100;
		message.m_TgtInfo2[i][9] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtVE / 100;
		message.m_TgtInfo2[i][10] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtAccN / 2;
		message.m_TgtInfo2[i][11] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtAccU / 2;
		message.m_TgtInfo2[i][12] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtAccE / 2;
		message.m_TgtInfo2[i][13] = (float) _rawData.m_HMDInfo.m_TgtInfo[i].m_fTgtDisDot / 100;
	}

	message.m_eAircraftMainState = 	(float) _rawData.m_FCInfo.m_eAircraftMainState;
	message.m_fRmax = 				(float) _rawData.m_FCInfo.m_fRmax;
	message.m_fRnoescape = 			(float) _rawData.m_FCInfo.m_fRnoescape;
	message.m_fRmin = 				(float) _rawData.m_FCInfo.m_fRmin;
	message.m_bINRNG = 				(float) _rawData.m_FCInfo.m_bINRNG;
	message.m_bSHOOT = 				(float) _rawData.m_FCInfo.m_bSHOOT;
	message.m_bWeaponReady = 		(float) _rawData.m_FCInfo.m_bWeaponReady;

	message.m_uiAlarmTgtNum = (float) _rawData.m_ESMInfo.m_uiAlarmTgtNum;
	for(int i=0; i<MAX_TGT_NUM; i++)
	{
		message.m_AlarmTgtInfo[i][0] = (float) _rawData.m_ESMInfo.m_AlarmTgtInfo[i].m_uiTgtLot;
		message.m_AlarmTgtInfo[i][1] = (float) _rawData.m_ESMInfo.m_AlarmTgtInfo[i].m_eTgtType;
		message.m_AlarmTgtInfo[i][2] = (float) _rawData.m_ESMInfo.m_AlarmTgtInfo[i].m_eTgtIff;
		message.m_AlarmTgtInfo[i][3] = (float) _rawData.m_ESMInfo.m_AlarmTgtInfo[i].m_fTgtAzi;
		message.m_AlarmTgtInfo[i][4] = (float) _rawData.m_ESMInfo.m_AlarmTgtInfo[i].m_fTgtEle;
	}

	message.m_uiThreatTgtNum = (float) _rawData.m_DASInfo.m_uiThreatTgtNum;
	for(int i=0; i<MAX_TGT_NUM; i++)
	{
		message.m_ThreatTgtInfo[i][0] = (float) _rawData.m_DASInfo.m_ThreatTgtInfo[i].m_uiTgtLot;
		message.m_ThreatTgtInfo[i][1] = (float) _rawData.m_DASInfo.m_ThreatTgtInfo[i].m_fTgtAzi;
		message.m_ThreatTgtInfo[i][2] = (float) _rawData.m_DASInfo.m_ThreatTgtInfo[i].m_fTgtEle;
	}

	message.m_uiTgtNum3 = (float) _rawData.m_AWACSInfo.m_uiTgtNum;
	for(int i=0; i<MAX_TGT_NUM; i++)
	{
		message.m_TgtInfo3[i][0] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_uiTgtLot;
		message.m_TgtInfo3[i][1] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_eIFF;
		message.m_TgtInfo3[i][2] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtLon;
		message.m_TgtInfo3[i][3] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtLat;
		message.m_TgtInfo3[i][4] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtAlt;
		message.m_TgtInfo3[i][5] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtVN;
		message.m_TgtInfo3[i][6] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtVU;
		message.m_TgtInfo3[i][7] = (float) _rawData.m_AWACSInfo.m_TgtInfo[i].m_fTgtVE;
	}

	message.m_uiMsgNum = (float) _rawData.m_MRAAMDataMsgSet.m_uiMsgNum;
	for(int i=0; i<MAX_MRAAM_NUM; i++)
	{
		message.m_MRAAMDataMsg[i][0] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_uiAAMID;
		message.m_MRAAMDataMsg[i][1] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_bSeekerOpen;
		message.m_MRAAMDataMsg[i][2] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_bCapture;
		message.m_MRAAMDataMsg[i][3] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_dLon;
		message.m_MRAAMDataMsg[i][4] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_dLat;
		message.m_MRAAMDataMsg[i][5] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_dAlt;
		message.m_MRAAMDataMsg[i][6] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_fMslVX;
		message.m_MRAAMDataMsg[i][7] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_fMslVU;
		message.m_MRAAMDataMsg[i][8] = (float) _rawData.m_MRAAMDataMsgSet.m_MRAAMDataMsg[i].m_fMslVE;
	}

	message.m_iAAMNum = (float) _rawData.m_AAMDataSet.m_iAAMNum;
	for(int i=0; i<MAX_AAM_NUM_IN_SCENE; i++)
	{
		message.m_AAMData[i][0] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_uiAAMID;
		message.m_AAMData[i][1] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_eAAMType;
		message.m_AAMData[i][2] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_uiPlaneID;
		message.m_AAMData[i][3] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_eAAMState;
		message.m_AAMData[i][4] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_bSeekerOpen;
		message.m_AAMData[i][5] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_bCapture;
		message.m_AAMData[i][6] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_dLon;
		message.m_AAMData[i][7] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_dLat;
		message.m_AAMData[i][8] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_dAlt;
		message.m_AAMData[i][9] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fMslVX;
		message.m_AAMData[i][10] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fMslVU;
		message.m_AAMData[i][11] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fMslVE;
		message.m_AAMData[i][12] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fMslYaw;
		message.m_AAMData[i][13] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fMslPitch;
		message.m_AAMData[i][14] = (float) _rawData.m_AAMDataSet.m_AAMData[i].m_fTgtDis;
	}
}


void AIPilot_TeamName::write2acmi()
{
	// 如果是红方，则添加时间标签
	if (m_eIFF == Enum_AircraftIff_Red)
	{
		fout << "#" << m_Input.m_AircraftBasicInfo.m_lTimeStamp / 1000.0f << "\n";
	}
	// 飞行器的坐标和姿态角
	fout.precision(6);
	fout << m_Input.m_AircraftBasicInfo.m_ID << ", "
		<< "T=" << m_Input.m_AircraftMoveInfo.m_dSelfLon << "|";
	fout.precision(14);
	fout << m_Input.m_AircraftMoveInfo.m_dSelfLat << "|"
		<< m_Input.m_AircraftMoveInfo.m_dSelfAlt << "|";
	fout.precision(6);
	fout<< m_Input.m_AircraftMoveInfo.m_fRoll / PI * 180 << "|"
		<< m_Input.m_AircraftMoveInfo.m_fPitch / PI * 180 << "|"
		<< m_Input.m_AircraftMoveInfo.m_fYaw / PI * -180 << ", "
		<< "TAS=" << m_Input.m_AircraftMoveInfo.m_fTASpeed << ", "
		<< "Mach=" << m_Input.m_AircraftMoveInfo.m_fMach << ", "
		<< "AOA=" << m_Input.m_AircraftMoveInfo.m_fAlpha << ", "
		<< "AOS=" << m_Input.m_AircraftMoveInfo.m_fBeta << ", "
		<< "Throttle=" << m_Output.m_FlyCtrlCmd.m_fThrottle << ", "
		<< "FuelWeight=" << m_Input.m_AircraftBasicInfo.m_fFuel << ", "
		<< "VerticalGForce=" << m_Input.m_AircraftMoveInfo.m_fNormalAccel << ", ";

	// 火控雷达目标锁定
	if (m_Input.m_RadarInfo.m_uiTgtNum > 0)
	{
		for (int i = 0; i < m_Input.m_RadarInfo.m_uiTgtNum; i++)
		{
			fout << "LockedTarget=" << 302 - m_Input.m_AircraftBasicInfo.m_ID << ", "
				<< "LockedTargetMode=1, "
				<< "LockedTargetAzimuth=" << m_Input.m_RadarInfo.m_TgtInfo[i].m_fTgtAzi / PI * 180 << ", "
				<< "LockedTargetElevation=" << m_Input.m_RadarInfo.m_TgtInfo[i].m_fTgtEle / PI * 180 << ", "
				<< "LockedTargetRange=" << m_Input.m_RadarInfo.m_TgtInfo[i].m_fTgtDis << ", ";
		}
	}
	else
	{
		fout << "LockedTargetMode=0, ";
	}

	// 火控雷达扫描范围显示
	float radarBias = 0.0;
	if (m_Input.m_RadarInfo.m_eRadarWorkMode == Enum_RadarWorkMode_WVR)
		radarBias = 23.0;
	fout << "RadarMode=" << (int)m_Input.m_RadarInfo.m_eRadarWorkMode << ", "
		<< "RadarAzimuth=" << m_Input.m_RadarInfo.m_fAziScanCent / PI * 180 << ", "
		<< "RadarElevation=" << (m_Input.m_RadarInfo.m_fEleScanCent - m_Input.m_AircraftMoveInfo.m_fAlpha) / PI * 180 + radarBias << ", "
		<< "RadarRange=" << 220000 << ", "
		<< "RadarHorizontalBeamwidth=" << m_Input.m_RadarInfo.m_fAziScanRange / PI * 180 << ", "
		<< "RadarVerticalBeamwidth=" << m_Input.m_RadarInfo.m_fEleScanRange / PI * 180 << std::endl;

	// 空空导弹发射
	for (int i = 0; i < MAX_AAM_NUM_IN_SCENE; i++)
	{
		if ((m_Input.m_AAMDataSet.m_AAMData[i].m_eAAMState == Enum_AAMState_Flying) && (m_Input.m_AAMDataSet.m_AAMData[i].m_fTgtDis > 20))
		{
			fout << m_Input.m_AAMDataSet.m_AAMData[i].m_uiAAMID << ", ";
			fout.precision(14);
			fout << "T=" << m_Input.m_AAMDataSet.m_AAMData[i].m_dLon << "|"
				<< m_Input.m_AAMDataSet.m_AAMData[i].m_dLat << "|";
			fout.precision(6);
			fout<< m_Input.m_AAMDataSet.m_AAMData[i].m_dAlt << "||"
				<< m_Input.m_AAMDataSet.m_AAMData[i].m_fMslPitch / PI * 180 << "|"
				<< m_Input.m_AAMDataSet.m_AAMData[i].m_fMslYaw / PI * -180 << ", ";
			if (m_eIFF == Enum_AircraftIff_Red)
			{
				fout << "Type=Weapon+Missile,Name=AIM-9X,Color=Red, "
					<< "Parent=" << m_Input.m_AAMDataSet.m_AAMData[i].m_uiPlaneID << std::endl;
			}
			else
			{
				fout << "Type=Weapon+Missile,Name=AIM-9X,Color=Blue, "
					<< "Parent=" << m_Input.m_AAMDataSet.m_AAMData[i].m_uiPlaneID << std::endl;
			}
		}
		//else if ((m_Input.m_AAMDataSet.m_AAMData[i].m_eAAMState == Enum_AAMState_Hit) || ((m_Input.m_AAMDataSet.m_AAMData[i].m_eAAMState == Enum_AAMState_Flying) && (m_Input.m_AAMDataSet.m_AAMData[i].m_fTgtDis <= 20)))
		//{
		//	fout << "0,Event=Message|"
		//		<< m_Input.m_AAMDataSet.m_AAMData[i].m_uiAAMID
		//		<< "|Hit the target" << std::endl;
		//}
		else if (m_Input.m_AAMDataSet.m_AAMData[i].m_eAAMState == Enum_AAMState_Lost)
		{
			fout << "0,Event=Message|"
				<< m_Input.m_AAMDataSet.m_AAMData[i].m_uiAAMID
				<< "|Lost the target" << std::endl;
		}
	}
}


bool AIPilot_TeamName::Step()
{
	// 序列化数据，并通过socket发送至python服务器
	//serialize();
	//send(sockClient, (char*)&message, sizeof(message)+1, 0);
	//char recvBuf[50];
	//recv(sockClient, recvBuf, 20, 0);

	

	// 测试libtorch
	//torch::Tensor tensor;
	//fout << tensor << std::endl;
	

	/////////////////////////////////////////////////////////////////////////////
	//m_Output = m_strategy.Track(&m_Input);
	m_strategy.JustifyPose(&m_Input);
	//m_Output = m_strategy.LevelOff(&m_Input,FlightStrategyClass::KeepEnergy);
	if(m_Input.m_FCInfo.m_bWeaponReady)
		m_Output.m_WeaponCtrlCmd.m_bWeaponLaunch= true;

	//m_Output.m_WeaponCtrlCmd.m_bWeaponLaunch = false;
	/////////////////////////////////////////////////////////////////////////////
	// 态势信息写入到acmi
	write2acmi();

	return true;
}


bool AIPilot_TeamName::Delete()
{
	delete this;
	return true;
}


bool AIPilot_TeamName::IsUpdate()
{
	return true;
}


void* AIPilot_TeamName::getInput()
{
	return (void*)&m_Input;
}


void* AIPilot_TeamName::getOutput()
{
	return (void*)&m_Output;
}