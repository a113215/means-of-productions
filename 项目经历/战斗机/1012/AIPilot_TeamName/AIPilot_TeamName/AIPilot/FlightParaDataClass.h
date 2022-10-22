#pragma once
//stl头文件没有.h扩展名
#include<map>
using namespace std;
#define MATIMES 100
typedef struct FireCond {
	int veloc_int;	//为双机速度*10
	int angle;
	int altitude;
}FireCond;
class FlightParaDataClass
{
public:
	enum Mode {Internal=0,BeyondVisition};
	FlightParaDataClass();
	/*
	brief:导弹最大攻击距离
	param:
			veloc  双机速度
			angle		进入角
			altitude	高度
			mode    近距模式\超距模式
	*/
	int FireRange(float veloc,int angle,int altitude, Mode mode=Internal);
	/*
	brief:最大最小平飞速度
	param:
			
	*/
	int MinLevelVeloc(int altitude,Mode mode=Internal);
	int MaxLevelVeloc(int altitude, Mode mode = Internal);
private:
	/*
	brief:生成最大攻击距离表
	*/
	void FormatRanges();
	/*
	brief:生成最大最小平飞速度表
	*/
	void FormatLevelVeloc();
	//brief:最大攻击距离数据表
	map<FireCond,int> m_maxRanges;
	//说明：为保持整型变量存储---速度值采用*MATIMES保存（单位：马赫）
	map<int, int> m_minLevelVeloc;
	map<int, int> m_maxLevelVeloc;
};

