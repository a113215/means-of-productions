#pragma once
//stlͷ�ļ�û��.h��չ��
#include<map>
#include<math.h>
using namespace std;
#define MATIMES 100
#define ERRORRANGE 0.1
#define PI 3.14159
typedef struct FireCond {
	int veloc_int;	//Ϊ˫���ٶ�*10
	int angle;
	int altitude;
}FireCond;
class FlightParaDataClass
{
public:
	enum Mode {Internal=0,BeyondVisition};
	FlightParaDataClass();
	/*
	brief:������󹥻�����
	param:
			veloc  ˫���ٶ�
			angle		�����
			altitude	�߶�
			mode    ����ģʽ\����ģʽ
	*/
	int FireRange(float veloc,int angle,int altitude, Mode mode=Internal);
	/*
	brief:�����Сƽ���ٶ�
	param:
			altitude �߶Ȳ���
			mode		�Ӿ���ģʽ|�Ӿ���ģʽ
	*/
	int MinLevelVeloc(int altitude,Mode mode=Internal);
	int MaxLevelVeloc(int altitude, Mode mode = Internal);
	/*
	brief:���ݸ��������ݸ�ǿ�ȣ�
	param 
		pitchSpan (-3.14,3.14) Ϊ��ʼ����ֵ-Ŀ�ĸ���ֵ
	*/
	float StickLon(float pitchSpan);
	/*
	brief:���ݷ�λ���ýŵ�ǿ�ȣ�
	param
		yawSpan (-3.14,3.14) Ϊ��ʼ��λֵ-Ŀ�ķ�λֵ(ȡ��ǰ��ͷΪ����0,��ʱ��Ϊ��)
	*/
	float StickRudder(float yawSpan);
	/*
	brief:���ݷ�λ���ú��ǿ�ȣ�
	param
		rollSpan (-3.14,3.14) Ϊ��ʼ��λֵ-Ŀ�ķ�λֵ(ȡ��ǰ��ͷΪ����0,��ʱ��Ϊ��)
	*/
	float StickLat(float rollSpan);
	/*
	brief :���ݵ�ǰ��Ϣ�������ǿ�ȣ���׷������£�
	param:
		veloc		��ǰ���
		velocSpan
		altitude	�߶�(km)
	*/
	//float StickThrottle(float veloc,float velocSpan,int altitude);
private:
	/*
	brief:������󹥻������
	*/
	void FormatRanges();
	/*
	brief:���������Сƽ���ٶȱ�
	*/
	void FormatLevelVeloc();
	//brief:��󹥻��������ݱ�
	map<FireCond,int> m_maxRanges;
	//˵����Ϊ�������ͱ����洢---�ٶ�ֵ����*MATIMES���棨��λ����գ�
	map<int, int> m_minLevelVeloc;
	map<int, int> m_maxLevelVeloc;
};

