#include "CreateAndRelease.h"
#include <stdio.h>
#include <map>

std::map<unsigned short, AIPilot_TeamName*> g_mapInstances_AIPilot_TeamName;

AIPilot* CreateInstance(unsigned short index)
{
	// 在此处添加创建各自的算法类实例代码......
	AIPilot_TeamName* _pInstance = NULL;
	_pInstance = new AIPilot_TeamName;
	g_mapInstances_AIPilot_TeamName.insert(std::pair<unsigned short, AIPilot_TeamName*>(index, _pInstance));

	// 返回创建的算法类实例指针
	return (AIPilot*)_pInstance;
}

void ReleaseInstance(unsigned short index)
{
	//if (pInstance != NULL)
	//{
	//	AIPilot_TeamName* _p = (AIPilot_TeamName*)pInstance;
	//	delete _p;
	//	_p = NULL;
	//	pInstance = NULL;
	//}
	std::map<unsigned short, AIPilot_TeamName*>::iterator _iter;
	_iter = g_mapInstances_AIPilot_TeamName.find(index);
	if (_iter != g_mapInstances_AIPilot_TeamName.end())
	{
		AIPilot_TeamName* _pInstance = _iter->second;
		delete _pInstance;
		_pInstance = NULL;
		g_mapInstances_AIPilot_TeamName.erase(_iter);
	}

	return;
}