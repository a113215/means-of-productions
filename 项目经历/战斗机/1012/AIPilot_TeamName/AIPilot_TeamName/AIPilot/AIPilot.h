#pragma once

#ifdef AIPILOT_EXPORTS
#define AIPILOT_API __declspec(dllexport)
#else
#define AIPILOT_API __declspec(dllimport)
#endif
#pragma warning(disable:4786)

#include "AI_Interface.h"

// �����㷨��װ����
class AIPILOT_API AIPilot
{

public:
	// ��ʼ��
	virtual bool Init(void* pInitData, unsigned short index) = 0;

	// ����һ��
	virtual bool Step() = 0;

	// ɾ��
	virtual bool Delete() = 0;

	// ����
	virtual bool IsUpdate() = 0;

	// ��ȡ������������ָ��
	virtual void* getInput() = 0;

	// ��ȡ�����������ָ��
	virtual void* getOutput() = 0;

};
