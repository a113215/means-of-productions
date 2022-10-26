#pragma once

#ifdef AIPILOT_EXPORTS
#define AIPILOT_API __declspec(dllexport)
#else
#define AIPILOT_API __declspec(dllimport)
#endif
#pragma warning(disable:4786)

#include "AI_Interface.h"

// 智能算法封装基类
class AIPILOT_API AIPilot
{

public:
	// 初始化
	virtual bool Init(void* pInitData, unsigned short index) = 0;

	// 决策一步
	virtual bool Step() = 0;

	// 删除
	virtual bool Delete() = 0;

	// 更新
	virtual bool IsUpdate() = 0;

	// 获取决策输入数据指针
	virtual void* getInput() = 0;

	// 获取决策输出数据指针
	virtual void* getOutput() = 0;

};
