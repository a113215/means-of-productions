#ifndef __AI_INTERFACE_H__
#define __AI_INTERFACE_H__

//----------------------------------------------- �������� -----------------------------------------------

#define MAX_TGT_NUM 8
#define MAX_MRAAM_NUM 6				// ����������ص�����о�տյ�������
#define MAX_SRAAM_NUM 6				// ����������ص�������տյ�������
#define MAX_AAM_NUM_IN_SCENE 12		// ���泡������������տյ�������


//--------------------------------------------- ���ݽṹ���� ---------------------------------------------

// ����ɻ�ʵ�����㷨ģ�鷢�͵ı�������״̬��Ϣ
struct SAircraftBasicInfo_AI_Interface
{
	unsigned short	m_ID;			// ����ID

	unsigned long	m_lTimeStamp;	// ʱ�꣨���濪ʼʱ��Ϊ0����λ�����룩

	bool			m_bAlive;		// ���״̬���ɻ����ʱΪtrue������Ϊfalse��

	float			m_fFuel;		// ʣ��ȼ�ͣ���λ��ǧ�ˣ�

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

// ����ɻ�ʵ�����㷨ģ�鷢�͵ı����˶�״̬��Ϣ
struct SAircraftMoveInfo_AI_Interface
{
	double			m_dSelfLon;		// �������ȣ�����Ϊ��������Ϊ������λ���ȣ�

	double			m_dSelfLat;		// ����γ�ȣ���γΪ������γΪ������λ���ȣ�

	double			m_dSelfAlt;		// �����߶ȣ����θ߶ȣ���λ���ף�

	float			m_fVN;			// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩

	float			m_fVU;			// ���������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩

	float			m_fVE;			// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩

	float			m_fAccN;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fAccU;		// ����������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fAccE;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fAccBX;		// ��������ϵX������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fAccBY;		// ��������ϵY������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fAccBZ;		// ��������ϵZ������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��

	float			m_fTASpeed;		// ��������٣���λ����/�룩

	float			m_fMach;		// �������������λ����գ�

	float			m_fNormalAccel;	// ����������أ���λ��G��

	float			m_fYaw;			// ����ƫ���ǣ�����Ϊ0����ʱ����תΪ������λ�����ȣ�

	float			m_fPitch;		// ���������ǣ��ɻ�ƽ��ʱΪ0��̧ͷΪ������λ�����ȣ�

	float			m_fRoll;		// ������ת�ǣ��ɻ�ƽ��ʱΪ0���ҹ�תΪ������λ�����ȣ�

	float			m_fAlpha;		// �������ǣ���ͷ������������ʱΪ������λ�����ȣ�

	float			m_fBeta;		// �����໬�ǣ���ͷƫ�������Ҳ�ʱΪ������λ�����ȣ�

	float			m_fCrab;		// ����ƫ���ǣ���λ�����ȣ�

	float			m_fOmegaYaw;	// ����ƫ�����ٶȣ���ʱ����תΪ������λ������/�룩

	float			m_fOmegaPitch;	// �����������ٶȣ��ɻ�̧ͷʱΪ������λ������/�룩

	float			m_fOmegaRoll;	// ������ת���ٶȣ��ɻ����ҹ�תʱΪ������λ������/�룩

	SAircraftMoveInfo_AI_Interface()
	{
		m_dSelfLon		= 0;		// �������ȣ�����Ϊ��������Ϊ������λ���ȣ�
		m_dSelfLat		= 0;		// ����γ�ȣ���γΪ������γΪ������λ���ȣ�
		m_dSelfAlt		= 0;		// �����߶ȣ����θ߶ȣ���λ���ף�
		m_fVN			= 0;		// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fVU			= 0;		// ���������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fVE			= 0;		// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fAccN			= 0;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccU			= 0;		// ����������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccE			= 0;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBX		= 0;		// ��������ϵX������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBY		= 0;		// ��������ϵY������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBZ		= 0;		// ��������ϵZ������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fTASpeed		= 0;		// ��������٣���λ����/�룩
		m_fMach			= 0;		// �������������λ����գ�
		m_fNormalAccel	= 0;		// ����������أ���λ��G��
		m_fYaw			= 0;		// ����ƫ���ǣ�����Ϊ0����ʱ����תΪ������λ�����ȣ�
		m_fPitch		= 0;		// ���������ǣ��ɻ�ƽ��ʱΪ0��̧ͷΪ������λ�����ȣ�
		m_fRoll			= 0;		// ������ת�ǣ��ɻ�ƽ��ʱΪ0���ҹ�תΪ������λ�����ȣ�
		m_fAlpha		= 0;		// �������ǣ���ͷ������������ʱΪ������λ�����ȣ�
		m_fBeta			= 0;		// �����໬�ǣ���ͷƫ�������Ҳ�ʱΪ������λ�����ȣ�
		m_fCrab			= 0;		// ����ƫ���ǣ���λ�����ȣ�
		m_fOmegaYaw		= 0;		// ����ƫ�����ٶȣ���ʱ����תΪ������λ������/�룩
		m_fOmegaPitch	= 0;		// �����������ٶȣ��ɻ�̧ͷʱΪ������λ������/�룩
		m_fOmegaRoll	= 0;		// ������ת���ٶȣ��ɻ����ҹ�תʱΪ������λ������/�룩
	}

	SAircraftMoveInfo_AI_Interface &operator = (const SAircraftMoveInfo_AI_Interface &_info)
	{
		m_dSelfLon		= _info.m_dSelfLon;		// �������ȣ�����Ϊ��������Ϊ������λ���ȣ�
		m_dSelfLat		= _info.m_dSelfLat;		// ����γ�ȣ���γΪ������γΪ������λ���ȣ�
		m_dSelfAlt		= _info.m_dSelfAlt;		// �����߶ȣ����θ߶ȣ���λ���ף�
		m_fVN			= _info.m_fVN;			// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fVU			= _info.m_fVU;			// ���������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fVE			= _info.m_fVE;			// ���������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/�룩
		m_fAccN			= _info.m_fAccN;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccU			= _info.m_fAccU;		// ����������ٶȣ�����Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccE			= _info.m_fAccE;		// ����������ٶȣ���Ϊ�����Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBX		= _info.m_fAccBX;		// ��������ϵX������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBY		= _info.m_fAccBY;		// ��������ϵY������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fAccBZ		= _info.m_fAccBZ;		// ��������ϵZ������ٶȣ��Ե�ǰ�ɻ�����Ϊԭ�㣬��λ����/��2��
		m_fTASpeed		= _info.m_fTASpeed;		// ��������٣���λ����/�룩
		m_fMach			= _info.m_fMach;		// �������������λ����գ�
		m_fNormalAccel	= _info.m_fNormalAccel;	// ����������أ���λ��G��
		m_fYaw			= _info.m_fYaw;			// ����ƫ���ǣ�����Ϊ0����ʱ����תΪ������λ�����ȣ�
		m_fPitch		= _info.m_fPitch;		// ���������ǣ��ɻ�ƽ��ʱΪ0��̧ͷΪ������λ�����ȣ�
		m_fRoll			= _info.m_fRoll;		// ������ת�ǣ��ɻ�ƽ��ʱΪ0���ҹ�תΪ������λ�����ȣ�
		m_fAlpha		= _info.m_fAlpha;		// �������ǣ���ͷ������������ʱΪ������λ�����ȣ�
		m_fBeta			= _info.m_fBeta;		// �����໬�ǣ���ͷƫ�������Ҳ�ʱΪ������λ�����ȣ�
		m_fCrab			= _info.m_fCrab;		// ����ƫ���ǣ���λ�����ȣ�
		m_fOmegaYaw		= _info.m_fOmegaYaw;	// ����ƫ�����ٶȣ���ʱ����תΪ������λ������/�룩
		m_fOmegaPitch	= _info.m_fOmegaPitch;	// �����������ٶȣ��ɻ�̧ͷʱΪ������λ������/�룩
		m_fOmegaRoll	= _info.m_fOmegaRoll;	// ������ת���ٶȣ��ɻ����ҹ�תʱΪ������λ������/�룩
		return *this;
	}
};

// ����ɻ�ʵ����ػ���״�̽�⵽�ĵ���Ŀ�����Ϣ
struct SRadarTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;				// Ŀ������

	float			m_fTgtDis;				// Ŀ����루�״�̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�

	float			m_fTgtAzi;				// Ŀ�귽λ�ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µķ�λ�ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µķ�λ�ǣ���λ������

	float			m_fTgtEle;				// Ŀ�긩���ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µĸ����ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µĸ����ǣ���λ������

	float			m_fTgtVN;				// Ŀ��ı����ٶȣ���λ����/��

	float			m_fTgtVU;				// Ŀ��������ٶȣ���λ����/��

	float			m_fTgtVE;				// Ŀ��Ķ����ٶȣ���λ����/��

	float			m_fTgtAccN;				// Ŀ��ı�����ٶȣ���λ����/��2

	float			m_fTgtAccU;				// Ŀ���������ٶȣ���λ����/��2

	float			m_fTgtAccE;				// Ŀ��Ķ�����ٶȣ���λ����/��2

	float			m_fTgtDisDot;			// Ŀ��ľ����ٶȣ���λ����/��

	SRadarTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;					// Ŀ������
		m_fTgtDis	= 0;					// Ŀ����루�״�̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAzi	= 0;					// Ŀ�귽λ�ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µķ�λ�ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µķ�λ�ǣ���λ������
		m_fTgtEle	= 0;					// Ŀ�긩���ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µĸ����ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µĸ����ǣ���λ������
		m_fTgtVN	= 0;					// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= 0;					// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= 0;					// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= 0;					// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= 0;					// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= 0;					// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= 0;					// Ŀ��ľ����ٶȣ���λ����/��
	}

	SRadarTgtInfo_AI_Interface &operator = (const SRadarTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;		// Ŀ������
		m_fTgtDis	= _info.m_fTgtDis;		// Ŀ����루�״�̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAzi	= _info.m_fTgtAzi;		// Ŀ�귽λ�ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µķ�λ�ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µķ�λ�ǣ���λ������
		m_fTgtEle	= _info.m_fTgtEle;		// Ŀ�긩���ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µĸ����ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µĸ����ǣ���λ������
		m_fTgtVN	= _info.m_fTgtVN;		// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= _info.m_fTgtVU;		// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= _info.m_fTgtVE;		// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= _info.m_fTgtAccN;		// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= _info.m_fTgtAccU;		// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= _info.m_fTgtAccE;		// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= _info.m_fTgtDisDot;	// Ŀ��ľ����ٶȣ���λ����/��
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;					// Ŀ������
		m_fTgtDis	= 0;					// Ŀ����루�״�̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAzi	= 0;					// Ŀ�귽λ�ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µķ�λ�ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µķ�λ�ǣ���λ������
		m_fTgtEle	= 0;					// Ŀ�긩���ǣ��״﹤���ڳ��Ӿ�ģʽ��ʱ���ýǶ�Ϊ����ϵ�µĸ����ǣ����Ӿ���ģʽ��ʱ��Ϊ����ϵ�µĸ����ǣ���λ������
		m_fTgtVN	= 0;					// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= 0;					// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= 0;					// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= 0;					// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= 0;					// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= 0;					// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= 0;					// Ŀ��ľ����ٶȣ���λ����/��
	}
};

// �״﹤��ģʽ����
enum Enum_RadarWorkMode
{
	Enum_RadarWorkMode_OFF = 0,						// �ػ�

	Enum_RadarWorkMode_BVR = 1,						// ���Ӿ�ģʽ

	Enum_RadarWorkMode_WVR = 2						// �Ӿ���ģʽ
};

// ����ɻ�ʵ�����㷨ģ�鷢�͵ı������ػ���״��ȡ��Ŀ����Ϣ
struct SRadarInfo_AI_Interface
{
	Enum_RadarWorkMode			m_eRadarWorkMode;		// �״﹤��ģʽ

	float						m_fAziScanRange;		// �״�ɨ�跽λ��Χ����λ�����ȣ����Ӿ�ģʽ��Ϊ30�ȡ�60�ȡ�120���е�һ�����Ӿ���ģʽ��ʼ��Ϊ10�ȣ�

	float						m_fEleScanRange;		// �״�ɨ�踩����Χ����λ�����ȣ����Ӿ�ģʽ��Ϊ4.5��һ�У��Ӿ���ģʽ�¹̶�Ϊ60��[-7�ȣ�53��]��

	float						m_fAziScanCent;			// �״�ɨ�跽λ���ģ���λ�����ȣ���ֵ���ڳ��Ӿ�ģʽ�¿ɵ�����Ϊ����ϵ�µĽǶȣ��Ӿ���ģʽ��ʼ��Ϊ0��

	float						m_fEleScanCent;			// �״�ɨ�踩�����ģ���λ�����ȣ���ֵ���ڳ��Ӿ�ģʽ�¿ɵ�����Ϊ����ϵ�µĽǶȣ��Ӿ���ģʽ��ʼ��Ϊ0��

	unsigned short				m_uiTgtNum;				// �״�̽�⵽��Ŀ������

	SRadarTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];	// �״�̽�⵽�ĸ���Ŀ�����Ϣ

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

// ����ɻ�ʵ����ͷ��̽�⵽�ĵ���Ŀ����Ϣ
struct SHMDTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;				// Ŀ�����ţ�����ÿһ��Ŀ�����Ψһ���ţ�

	float			m_fTgtDis;				// Ŀ����루���ͷ��̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�

	float			m_fTgtAziC;				// Ŀ���ڱ�������ϵ�µķ�λ�ǣ���λ������

	float			m_fTgtEleC;				// Ŀ���ڱ�������ϵ�µĸ����ǣ���λ������

	float			m_fYaw;					// Ŀ��ĺ���ǣ���λ������

	float			m_fPitch;				// Ŀ��ĸ����ǣ���λ������

	float			m_fRoll;				// Ŀ��Ĺ�ת�ǣ���λ������

	float			m_fTgtVN;				// Ŀ��ı����ٶȣ���λ����/��

	float			m_fTgtVU;				// Ŀ��������ٶȣ���λ����/��

	float			m_fTgtVE;				// Ŀ��Ķ����ٶȣ���λ����/��

	float			m_fTgtAccN;				// Ŀ��ı�����ٶȣ���λ����/��2

	float			m_fTgtAccU;				// Ŀ���������ٶȣ���λ����/��2

	float			m_fTgtAccE;				// Ŀ��Ķ�����ٶȣ���λ����/��2

	float			m_fTgtDisDot;			// Ŀ��ľ����ٶȣ���λ����/��

	SHMDTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;					// Ŀ������
		m_fTgtDis	= 0;					// Ŀ����루���ͷ��̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAziC	= 0;					// Ŀ���ڱ�������ϵ�µķ�λ�ǣ��ýǶ����Ӿ���ģʽ���������λ������
		m_fTgtEleC	= 0;					// Ŀ���ڱ�������ϵ�µĸ����ǣ��ýǶ����Ӿ���ģʽ���������λ������
		m_fYaw		= 0;					// Ŀ��ĺ���ǣ���λ������
		m_fPitch	= 0;					// Ŀ��ĸ����ǣ���λ������
		m_fRoll		= 0;					// Ŀ��Ĺ�ת�ǣ���λ������
		m_fTgtVN	= 0;					// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= 0;					// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= 0;					// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= 0;					// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= 0;					// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= 0;					// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= 0;					// Ŀ��ľ����ٶȣ���λ����/��
	}

	SHMDTgtInfo_AI_Interface &operator = (const SHMDTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;		// Ŀ������
		m_fTgtDis	= _info.m_fTgtDis;		// Ŀ����루���ͷ��̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAziC	= _info.m_fTgtAziC;		// Ŀ���ڱ�������ϵ�µķ�λ�ǣ���λ������
		m_fTgtEleC	= _info.m_fTgtEleC;		// Ŀ���ڱ�������ϵ�µĸ����ǣ���λ������
		m_fYaw		= _info.m_fYaw;			// Ŀ��ĺ���ǣ���λ������
		m_fPitch	= _info.m_fPitch;		// Ŀ��ĸ����ǣ���λ������
		m_fRoll		= _info.m_fRoll;		// Ŀ��Ĺ�ת�ǣ���λ������
		m_fTgtVN	= _info.m_fTgtVN;		// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= _info.m_fTgtVU;		// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= _info.m_fTgtVE;		// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= _info.m_fTgtAccN;		// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= _info.m_fTgtAccU;		// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= _info.m_fTgtAccE;		// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= _info.m_fTgtDisDot;	// Ŀ��ľ����ٶȣ���λ����/��
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;					// Ŀ������
		m_fTgtDis	= 0;					// Ŀ����루���ͷ��̽�⵽��Ŀ���뱾���ľ��룬��λ���ף�
		m_fTgtAziC	= 0;					// Ŀ���ڱ�������ϵ�µķ�λ�ǣ��ýǶ����Ӿ���ģʽ���������λ������
		m_fTgtEleC	= 0;					// Ŀ���ڱ�������ϵ�µĸ����ǣ��ýǶ����Ӿ���ģʽ���������λ������
		m_fYaw		= 0;					// Ŀ��ĺ���ǣ���λ������
		m_fPitch	= 0;					// Ŀ��ĸ����ǣ���λ������
		m_fRoll		= 0;					// Ŀ��Ĺ�ת�ǣ���λ������
		m_fTgtVN	= 0;					// Ŀ��ı����ٶȣ���λ����/��
		m_fTgtVU	= 0;					// Ŀ��������ٶȣ���λ����/��
		m_fTgtVE	= 0;					// Ŀ��Ķ����ٶȣ���λ����/��
		m_fTgtAccN	= 0;					// Ŀ��ı�����ٶȣ���λ����/��2
		m_fTgtAccU	= 0;					// Ŀ���������ٶȣ���λ����/��2
		m_fTgtAccE	= 0;					// Ŀ��Ķ�����ٶȣ���λ����/��2
		m_fTgtDisDot= 0;					// Ŀ��ľ����ٶȣ���λ����/��
	}
};

// ����ɻ�ʵ�����㷨ģ�鷢�͵ı������ͷ���ȡ��Ŀ����Ϣ
struct SHMDInfo_AI_Interface
{
	unsigned short				m_uiTgtNum;				// ���ͷ��̽�⵽��Ŀ������

	SHMDTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];	// ���ͷ��̽�⵽�ĸ���Ŀ�����Ϣ

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

// �ɻ�ϵͳ����ģʽ����
enum Enum_AircraftTaskMode
{
	Enum_AircraftTaskMode_BVR = 0,					// ���Ӿ�
	Enum_AircraftTaskMode_WVR = 1,					// �Ӿ���
};

// ����ɻ�ʵ�����㷨ģ�鷢�͵ı�����������Ϣ
struct SFCInfo_AI_Interface
{
	Enum_AircraftTaskMode m_eAircraftMainState;	// �ɻ�ϵͳ��ǰ��ģʽ

	float	m_fRmax;		// ������Ŀ���ڵ�ǰ�߶��ٶȼ�����������£���ȡƽ����̬ʱ�������Ե�ǰĿ�����󹥻�����

	float	m_fRnoescape;	// ������Ŀ���ڵ�ǰ�߶��ٶȼ�����������£���ȡƽ����̬ʱ�������Ե�ǰĿ��Ĳ������ݹ�������

	float	m_fRmin;		// ������Ŀ���ڵ�ǰ�߶��ٶȼ�����������£���ȡƽ����̬ʱ�������Ե�ǰĿ�����С�������룬���ڸþ���ʱ���������ܷ���

	bool	m_bINRNG;		// ������Ŀ���ڵ�ǰ�߶��ٶȼ�����������£���ȡƽ����̬ʱ��Ŀ���Ƿ���뵼����󹥻�����ı�־��

	bool	m_bSHOOT;		// ������Ŀ���ڵ�ǰ�߶��ٶȼ�����������£���ȡƽ����̬ʱ��Ŀ���Ƿ���뵼���������ݹ�������ı�־��

	bool	m_bWeaponReady;	// ��ǰ�Ƿ�������׼���ÿ��Է��䡣�������о�������ʱ���ж��Ƿ����о൯׼���ã������ڽ���������ʱ���ж��Ƿ��н��൯׼����

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

// ����ս�澯Ŀ�����Ͷ���
enum Enum_ESMTgtType
{	
	Enum_ESMTgtType_Invalid = 0,						// δ֪
	Enum_ESMTgtType_Missile = 1,						// ����	
	Enum_ESMTgtType_Plane	= 2							// �ɻ�	 
};

// ����ս�澯Ŀ�����ʶ������
enum Enum_ESMTgtIff
{
	Enum_ESMTgtIff_Friend	= 0,						// ��
	Enum_ESMTgtIff_Unknown	= 1,						// ����
	Enum_ESMTgtIff_Foe		= 2							// ��
};

// ����ɻ�ʵ�����㷨ģ�鷢�͵ĵ�������ս�澯Ŀ����Ϣ
struct SESMTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;		// �澯Ŀ�����ţ�ÿ���澯Ŀ�����Ψһ���ţ�

	Enum_ESMTgtType	m_eTgtType;		// �澯Ŀ�����ͣ����ڷɻ�����״�ĸ澯������Ϊ���ɻ��������ڵ�������ͷ�ĸ澯������Ϊ����������

	Enum_ESMTgtIff	m_eTgtIff;		// �澯Ŀ�����ʶ������

	float			m_fTgtAzi;		// �澯Ŀ���ڱ�������ϵ�µķ�λ�ǣ���λ�����ȣ�

	float			m_fTgtEle;		// �澯Ŀ���ڱ�������ϵ�µĸ����ǣ���λ�����ȣ�

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

// ����ɻ�ʵ�����㷨ģ�鷢�͵ĵ���ս�澯��Ϣ
struct SESMInfo_AI_Interface
{
	unsigned short				m_uiAlarmTgtNum;						// ��ǰ����ս�澯Ŀ������

	SESMTgtInfo_AI_Interface	m_AlarmTgtInfo[MAX_TGT_NUM];			// �����澯Ŀ�����Ϣ

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

// ����ɻ�ʵ�����㷨ģ�鷢�͵ĵ���DAS�澯Ŀ����Ϣ
struct SDASTgtInfo_AI_Interface
{
	unsigned short	m_uiTgtLot;		// �澯Ŀ�����ţ�ÿ���澯Ŀ�����Ψһ���ţ�

	float			m_fTgtAzi;		// �澯Ŀ���ڱ�������ϵ�µķ�λ�ǣ���λ�����ȣ�

	float			m_fTgtEle;		// �澯Ŀ���ڱ�������ϵ�µĸ����ǣ���λ�����ȣ�

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

// ����ɻ�ʵ�����㷨ģ�鷢�͵�DAS�澯��Ϣ
struct SDASInfo_AI_Interface
{
	unsigned short				m_uiThreatTgtNum;						// ��ǰDAS�澯Ŀ������

	SDASTgtInfo_AI_Interface	m_ThreatTgtInfo[MAX_TGT_NUM];			// ����DAS�澯Ŀ�����Ϣ

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
	Enum_AircraftIff_Red	= 0,					// �췽
	Enum_AircraftIff_Blue	= 1,					// ����
	Enum_AircraftIff_White	= 2						// �׷�
};

// ����ɻ�ʵ�����㷨ģ�鷢�͵ĵ����ⲿ��Ƶ��Ԥ��Ŀ����Ϣ
struct SAWACSTgtInfo_AI_Interface
{
	unsigned short		m_uiTgtLot;		// Ԥ��Ŀ�����ţ�ÿ��Ŀ�����Ψһ���ţ�

	Enum_AircraftIff	m_eIFF;			// Ԥ��Ŀ��ĵ���ʶ������

	float				m_fTgtLon;		// Ԥ��Ŀ�꾭�ȣ�����Ϊ��������Ϊ������λ���ȣ�

	float				m_fTgtLat;		// Ԥ��Ŀ��γ�ȣ���γΪ������γΪ������λ���ȣ�

	float				m_fTgtAlt;		// Ԥ��Ŀ��߶ȣ����θ߶ȣ���λ���ף�

	float				m_fTgtVN;		// Ԥ��Ŀ��ı����ٶȣ���λ����/�룩

	float				m_fTgtVU;		// Ԥ��Ŀ��������ٶȣ���λ����/�룩

	float				m_fTgtVE;		// Ԥ��Ŀ��Ķ����ٶȣ���λ����/�룩

	SAWACSTgtInfo_AI_Interface()
	{
		m_uiTgtLot	= 0;						// Ԥ��Ŀ�����ţ�ÿ��Ŀ�����Ψһ���ţ�
		m_eIFF		= Enum_AircraftIff_White;	// Ԥ��Ŀ��ĵ���ʶ������
		m_fTgtLon	= 0;						// Ԥ��Ŀ�꾭�ȣ�����Ϊ��������Ϊ������λ���ȣ�
		m_fTgtLat	= 0;						// Ԥ��Ŀ��γ�ȣ���γΪ������γΪ������λ���ȣ�
		m_fTgtAlt	= 0;						// Ԥ��Ŀ��߶ȣ����θ߶ȣ���λ���ף�
		m_fTgtVN	= 0;						// Ԥ��Ŀ��ı����ٶȣ���λ����/�룩
		m_fTgtVU	= 0;						// Ԥ��Ŀ��������ٶȣ���λ����/�룩
		m_fTgtVE	= 0;						// Ԥ��Ŀ��Ķ����ٶȣ���λ����/�룩
	}

	SAWACSTgtInfo_AI_Interface &operator = (const SAWACSTgtInfo_AI_Interface &_info)
	{
		m_uiTgtLot	= _info.m_uiTgtLot;			// Ԥ��Ŀ�����ţ�ÿ��Ŀ�����Ψһ���ţ�
		m_eIFF		= _info.m_eIFF;				// Ԥ��Ŀ��ĵ���ʶ������
		m_fTgtLon	= _info.m_fTgtLon;			// Ԥ��Ŀ�꾭�ȣ�����Ϊ��������Ϊ������λ���ȣ�
		m_fTgtLat	= _info.m_fTgtLat;			// Ԥ��Ŀ��γ�ȣ���γΪ������γΪ������λ���ȣ�
		m_fTgtAlt	= _info.m_fTgtAlt;			// Ԥ��Ŀ��߶ȣ����θ߶ȣ���λ���ף�
		m_fTgtVN	= _info.m_fTgtVN;			// Ԥ��Ŀ��ı����ٶȣ���λ����/�룩
		m_fTgtVU	= _info.m_fTgtVU;			// Ԥ��Ŀ��������ٶȣ���λ����/�룩
		m_fTgtVE	= _info.m_fTgtVE;			// Ԥ��Ŀ��Ķ����ٶȣ���λ����/�룩
		return *this;
	}

	void clear()
	{
		m_uiTgtLot	= 0;						// Ԥ��Ŀ�����ţ�ÿ��Ŀ�����Ψһ���ţ�
		m_eIFF		= Enum_AircraftIff_White;	// Ԥ��Ŀ��ĵ���ʶ������
		m_fTgtLon	= 0;						// Ԥ��Ŀ�꾭�ȣ�����Ϊ��������Ϊ������λ���ȣ�
		m_fTgtLat	= 0;						// Ԥ��Ŀ��γ�ȣ���γΪ������γΪ������λ���ȣ�
		m_fTgtAlt	= 0;						// Ԥ��Ŀ��߶ȣ����θ߶ȣ���λ���ף�
		m_fTgtVN	= 0;						// Ԥ��Ŀ��ı����ٶȣ���λ����/�룩
		m_fTgtVU	= 0;						// Ԥ��Ŀ��������ٶȣ���λ����/�룩
		m_fTgtVE	= 0;						// Ԥ��Ŀ��Ķ����ٶȣ���λ����/�룩
	}

};

// ����ɻ�ʵ�����㷨ģ��������ⲿ��Ƶ��Ԥ��Ŀ����Ϣ
struct SAWACSInfo_AI_Interface
{
	unsigned short			m_uiTgtNum;						// ��ǰ�ⲿԤ����Ϣ�а�����Ŀ������

	SAWACSTgtInfo_AI_Interface	m_TgtInfo[MAX_TGT_NUM];		// ����Ŀ�����Ϣ

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

// ��ö�о�տյ����Ļش���Ϣ
struct SMRAAMDataMsg_AI_Interface
{
	unsigned short		m_uiAAMID;				// �о�տյ���ID

	bool				m_bSeekerOpen;			// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������

	bool				m_bCapture;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�

	double				m_dLon;					// �������ȣ���λ���ȣ�

	double				m_dLat;					// ����γ�ȣ���λ���ȣ�

	double				m_dAlt;					// �����߶ȣ���λ���ף�

	float				m_fMslVX;				// ���������ٶȣ���λ����/�룩

	float				m_fMslVU;				// ���������ٶȣ���λ����/�룩

	float				m_fMslVE;				// ���������ٶȣ���λ����/�룩

	SMRAAMDataMsg_AI_Interface()
	{
		m_uiAAMID		= 0;					// �о�տյ���ID
		m_bSeekerOpen	= false;				// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= false;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= 0;					// �������ȣ���λ���ȣ�
		m_dLat			= 0;					// ����γ�ȣ���λ���ȣ�
		m_dAlt			= 0;					// �����߶ȣ���λ���ף�
		m_fMslVX		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVU		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVE		= 0;					// ���������ٶȣ���λ����/�룩
	}

	SMRAAMDataMsg_AI_Interface& operator = (const SMRAAMDataMsg_AI_Interface& _msg)
	{
		m_uiAAMID		= _msg.m_uiAAMID;		// �о�տյ���ID
		m_bSeekerOpen	= _msg.m_bSeekerOpen;	// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= _msg.m_bCapture;		// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= _msg.m_dLon;			// �������ȣ���λ���ȣ�
		m_dLat			= _msg.m_dLat;			// ����γ�ȣ���λ���ȣ�
		m_dAlt			= _msg.m_dAlt;			// �����߶ȣ���λ���ף�
		m_fMslVX		= _msg.m_fMslVX;		// ���������ٶȣ���λ����/�룩
		m_fMslVU		= _msg.m_fMslVU;		// ���������ٶȣ���λ����/�룩
		m_fMslVE		= _msg.m_fMslVE;		// ���������ٶȣ���λ����/�룩
		return *this;
	}

	void clear()
	{
		m_uiAAMID		= 0;					// �о�տյ���ID
		m_bSeekerOpen	= false;				// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= false;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= 0;					// �������ȣ���λ���ȣ�
		m_dLat			= 0;					// ����γ�ȣ���λ���ȣ�
		m_dAlt			= 0;					// �����߶ȣ���λ���ף�
		m_fMslVX		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVU		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVE		= 0;					// ���������ٶȣ���λ����/�룩
	}
};

// �о�տյ����ش���Ϣ����
struct SMRAAMDataMsgSet_AI_Interface
{
	unsigned short	m_uiMsgNum;					// �ش���Ϣ����
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

// �տյ������Ͷ���
enum Enum_AAMType
{
	Enum_AAMType_MRAAM = 0,			// �о�տյ���
	Enum_AAMType_SRAAM = 1			// ����տյ���
};

// �տյ���״̬����
enum Enum_AAMState
{
	Enum_AAMState_Unfired = 0,		// ����δ����
	Enum_AAMState_Flying = 1,		// ����������
	Enum_AAMState_Hit = 2,			// ����������
	Enum_AAMState_Lost = 3			// ������ʧЧ
};

// ��ö�տյ�����״̬��Ϣ
// ��ע���ò������ݽ������������㷨���Խ׶�ʹ�ã���ʽ����ʱ���ò�����������Ϊ��ֵ���㷨����ʱ����ʹ�ø����ݡ�
struct SAAMData_AI_Interface
{
	unsigned short		m_uiAAMID;				// �տյ���ID

	Enum_AAMType		m_eAAMType;				// �տյ�������

	unsigned short		m_uiPlaneID;			// ��ǰ�տ������ɻ�ID

	Enum_AAMState		m_eAAMState;			// �տյ���״̬

	bool				m_bSeekerOpen;			// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������

	bool				m_bCapture;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�

	double				m_dLon;					// �������ȣ���λ���ȣ�

	double				m_dLat;					// ����γ�ȣ���λ���ȣ�

	double				m_dAlt;					// �����߶ȣ���λ���ף�

	float				m_fMslVX;				// ���������ٶȣ���λ����/�룩

	float				m_fMslVU;				// ���������ٶȣ���λ����/�룩

	float				m_fMslVE;				// ���������ٶȣ���λ����/�룩

	float				m_fMslYaw;				// �������з�λ�ǣ���λ�����ȣ�

	float				m_fMslPitch;			// �������и����ǣ���λ�����ȣ�

	float				m_fTgtDis;				// ��Ŀ���루��λ���ף�

	SAAMData_AI_Interface()
	{
		m_uiAAMID		= 0;					// �տյ���ID
		m_eAAMType		= Enum_AAMType_MRAAM;	// �տյ�������
		m_uiPlaneID		= 0;					// ��ǰ�տ������ɻ�ID
		m_eAAMState		= Enum_AAMState_Unfired;// �տյ���״̬
		m_bSeekerOpen	= false;				// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= false;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= 0;					// �������ȣ���λ���ȣ�
		m_dLat			= 0;					// ����γ�ȣ���λ���ȣ�
		m_dAlt			= 0;					// �����߶ȣ���λ���ף�
		m_fMslVX		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVU		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVE		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslYaw		= 0;					// �������з�λ�ǣ���λ�����ȣ�
		m_fMslPitch		= 0;					// �������и����ǣ���λ�����ȣ�
		m_fTgtDis		= 0;					// ��Ŀ���루��λ���ף�
	}

	SAAMData_AI_Interface& operator = (const SAAMData_AI_Interface& _msg)
	{
		m_uiAAMID		= _msg.m_uiAAMID;		// �տյ���ID
		m_eAAMType		= _msg.m_eAAMType;		// �տյ�������
		m_uiPlaneID		= _msg.m_uiPlaneID;		// ��ǰ�տ������ɻ�ID
		m_eAAMState		= _msg.m_eAAMState;		// �տյ���״̬
		m_bSeekerOpen	= _msg.m_bSeekerOpen;	// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= _msg.m_bCapture;		// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= _msg.m_dLon;			// �������ȣ���λ���ȣ�
		m_dLat			= _msg.m_dLat;			// ����γ�ȣ���λ���ȣ�
		m_dAlt			= _msg.m_dAlt;			// �����߶ȣ���λ���ף�
		m_fMslVX		= _msg.m_fMslVX;		// ���������ٶȣ���λ����/�룩
		m_fMslVU		= _msg.m_fMslVU;		// ���������ٶȣ���λ����/�룩
		m_fMslVE		= _msg.m_fMslVE;		// ���������ٶȣ���λ����/�룩
		m_fMslYaw		= _msg.m_fMslYaw;		// �������з�λ�ǣ���λ�����ȣ�
		m_fMslPitch		= _msg.m_fMslPitch;		// �������и����ǣ���λ�����ȣ�
		m_fTgtDis		= _msg.m_fTgtDis;		// ��Ŀ���루��λ���ף�
		return *this;
	}

	void clear()
	{
		m_uiAAMID		= 0;					// �տյ���ID
		m_eAAMType		= Enum_AAMType_MRAAM;	// �տյ�������
		m_uiPlaneID		= 0;					// ��ǰ�տ������ɻ�ID
		m_eAAMState		= Enum_AAMState_Unfired;// �տյ���״̬
		m_bSeekerOpen	= false;				// ��������ͷ����״̬��true������ͷ�ѿ�����false������ͷδ������
		m_bCapture		= false;				// ��������ͷ�ػ�״̬��true������ͷ�ѽػ�false������ͷδ�ػ�
		m_dLon			= 0;					// �������ȣ���λ���ȣ�
		m_dLat			= 0;					// ����γ�ȣ���λ���ȣ�
		m_dAlt			= 0;					// �����߶ȣ���λ���ף�
		m_fMslVX		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVU		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslVE		= 0;					// ���������ٶȣ���λ����/�룩
		m_fMslYaw		= 0;					// �������з�λ�ǣ���λ�����ȣ�
		m_fMslPitch		= 0;					// �������и����ǣ���λ�����ȣ�
		m_fTgtDis		= 0;					// ��Ŀ���루��λ���ף�
	}
};

// �տյ���������Ϣ
// ��ע���ò������ݽ������������㷨���Խ׶�ʹ�ã���ʽ����ʱ���ò�����������Ϊ��ֵ���㷨����ʱ����ʹ�ø����ݣ�����
struct SAAMDataSet_AI_Interface
{
	int	m_iAAMNum;					// �տյ�������
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

// �㷨ģ������ӿڣ�������ɻ�ʵ�����㷨ģ�鷢�͵ı���״̬��̬�����ݣ�
struct AIPilotInput
{
	// ����������Ϣ
	SAircraftBasicInfo_AI_Interface	m_AircraftBasicInfo;

	// �����˶�״̬��Ϣ
	SAircraftMoveInfo_AI_Interface	m_AircraftMoveInfo;

	// �����״�̽�⵽��Ŀ����Ϣ
	SRadarInfo_AI_Interface			m_RadarInfo;

	// �������ͷ��̽�⵽��Ŀ����Ϣ
	SHMDInfo_AI_Interface			m_HMDInfo;

	// �������ϵͳ�����Ϣ
	SFCInfo_AI_Interface			m_FCInfo;

	// ��������ս�澯��Ϣ
	SESMInfo_AI_Interface			m_ESMInfo;

	// ����DAS�澯��Ϣ
	SDASInfo_AI_Interface			m_DASInfo;

	// �������յ����ⲿԤ����Ϣ
	SAWACSInfo_AI_Interface			m_AWACSInfo;

	// �о�տյ����ش���Ϣ
	SMRAAMDataMsgSet_AI_Interface	m_MRAAMDataMsgSet;

	// �տյ�������״̬��Ϣ
	// ��ע���ò������ݽ������������㷨���Խ׶�ʹ�ã���ʽ����ʱ���ò�����������Ϊ��ֵ���㷨����ʱ����ʹ�ø����ݡ�
	SAAMDataSet_AI_Interface		m_AAMDataSet;

	AIPilotInput()
	{

	}
};

// ƽ̨���п���ָ��㷨ģ�������ɻ�ʵ�������
struct SFlyCtrlCmd_AI_Interface
{
	float	m_fStickLat;			// �����λ�ƣ�ȡֵ��Χ��[-1,1]

	float	m_fStickLon;			// �����λ�ƣ�ȡֵ��Χ��[-1,1]

	float	m_fThrottle;			// ���Ÿ�λ�ƣ�ȡֵ��Χ��[0,1]

	float	m_fRudder;				// �ŵ�λ�ƣ�ȡֵ��Χ��[-1,1]

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

// ���ϵͳ����ָ��㷨ģ�������ɻ�ʵ�������
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

// �״￪�ػ���������
enum Enum_RadarOnOff
{
	Enum_RadarOnOff_OFF = 0,						// �ػ�
	Enum_RadarOnOff_ON	= 1							// ����
};

// �״�ɨ����������
enum Enum_RadarEleScanLine
{
	Enum_RadarEleScanLine_2	= 2,					// 2��ɨ��
	Enum_RadarEleScanLine_4	= 4						// 4��ɨ��
};

// �״﷽λɨ�跶Χ����
enum Enum_RadarAziScanRange
{
	Enum_RadarAziScanRange_30	= 30,				// 30��ɨ�跶Χ
	Enum_RadarAziScanRange_60	= 60,				// 60��ɨ�跶Χ
	Enum_RadarAziScanRange_120	= 120				// 120��ɨ�跶Χ
};

// ���ػ���״����ָ��㷨ģ�������ɻ�ʵ�������
struct SRadarCtrlCmd_AI_Interface
{
	Enum_RadarOnOff			m_eRadarOnOff;			// �״￪�ػ�����

	Enum_RadarEleScanLine	m_eEleScanLine;			// �״�ɨ��������ö��ֵ��ת��Ϊ������Ϊɨ����������λ���У�

	Enum_RadarAziScanRange	m_eAziScanRange;		// �״﷽λɨ�跶Χ��ö��ֵ��ת��Ϊ������Ϊɨ�跶Χ�ĽǶ�������λ���ȣ�

	float					m_fAziScanCent;			// �״�ɨ�跽λ���ģ���λ�����ȣ���ȡֵ��ΧӦ����(fabs(m_fAziScanCent)+fabs(m_eAziScanRange/2))<=(PI/3)

	float					m_fEleScanCent;			// �״�ɨ�踩�����ģ���λ�����ȣ���ȡֵ��ΧӦ����(fabs(m_fEleScanCent)+(4.5*D_TO_R*m_eEleScanLine/2))<=(PI/3)

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

// ������������ָ��㷨ģ�������ɻ�ʵ�������
struct SWeaponCtrlCmd_AI_Interface
{
	bool	m_bWeaponLaunch;						// �տյ�������ָ������ϵͳ�������㵼����������ʱ�������ǰ����ָ��Ϊtrue����ǰһ֡����ָ��Ϊfalse���򽫷���տյ���

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

// �㷨ģ������ӿڣ����㷨ģ����ɻ�ʵ�巢�͵ĸ������ָ�����ݣ�
struct AIPilotOutput
{
	// ƽ̨���п���ָ��
	SFlyCtrlCmd_AI_Interface	m_FlyCtrlCmd;

	// ���ϵͳ����ָ��
	SFCCtrlCmd_AI_Interface		m_FCCtrlCmd;

	// ���ػ���״����ָ��
	SRadarCtrlCmd_AI_Interface	m_RadarCtrlCmd;

	// ������������ָ��
	SWeaponCtrlCmd_AI_Interface	m_WeaponCtrlCmd;

	AIPilotOutput()
	{

	}
};

// �㷨ģ���ʼ���ӿ�
struct AIPilotInit
{
	unsigned short		m_ID;						// �ɻ�ID���ɻ���Ψһ��ʶ������0Ϊ��Чֵ��

	Enum_AircraftIff	m_eIFF;						// ����ʶ���־

	double				m_dInitLon;					// ��ʼλ�þ��ȣ�����Ϊ������λ���ȣ�

	double				m_dInitLat;					// ��ʼλ��γ�ȣ���γΪ������λ���ȣ�

	double				m_dInitAlt;					// ��ʼ���θ߶ȣ���λ���ף�

	float				m_fInitVelocity;			// ��ʼ�ٶȣ���λ����/�룩

	float				m_fInitYaw;					// ��ʼ��������Ϊ0����ʱ����תΪ������λ�����ȣ�

	float				m_fInitPitch;				// ��ʼ������ƽ��Ϊ0��̧ͷΪ������λ�����ȣ�

	float				m_fInitRoll;				// ��ʼ��ת��ƽ��Ϊ0�����¶�Ϊ������λ�����ȣ�

	unsigned short		m_uiMRAAMNum;				// ��ʼ�о൯����

	unsigned short		m_uiSRAAMNum;				// ��ʼ���൯����

	unsigned short		m_fInitFuel;				// ��ʼ����������λ��ǧ�ˣ�

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