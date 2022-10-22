#pragma once
//stlͷ�ļ�û��.h��չ��
#include<map>
using namespace std;
#define MATIMES 100
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
			
	*/
	int MinLevelVeloc(int altitude,Mode mode=Internal);
	int MaxLevelVeloc(int altitude, Mode mode = Internal);
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

