#pragma once
//stl头文件没有.h扩展名
#include<map>
#include<math.h>
using namespace std;
#define MATIMES 100
#define ERRORRANGE 0.1
#define PI 3.14159
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
			altitude 高度参数
			mode		视距内模式|视距外模式
	*/
	int MinLevelVeloc(int altitude,Mode mode=Internal);
	int MaxLevelVeloc(int altitude, Mode mode = Internal);
	/*
	brief:根据俯仰差获得纵杆强度，
	param 
		pitchSpan (-3.14,3.14) 为初始俯仰值-目的俯仰值
	*/
	float StickLon(float pitchSpan);
	/*
	brief:根据方位差获得脚蹬强度，
	param
		yawSpan (-3.14,3.14) 为初始方位值-目的方位值(取当前机头为正向0,逆时针为正)
	*/
	float StickRudder(float yawSpan);
	/*
	brief:根据方位差获得横杆强度，
	param
		rollSpan (-3.14,3.14) 为初始方位值-目的方位值(取当前机头为正向0,逆时针为正)
	*/
	float StickLat(float rollSpan);
	/*
	brief :根据当前信息获得油门强度（非追敌情况下）
	param:
		veloc		当前马赫
		velocSpan
		altitude	高度(km)
	*/
	//float StickThrottle(float veloc,float velocSpan,int altitude);
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

