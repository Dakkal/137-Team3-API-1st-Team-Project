#pragma once
#include "stdafx.h"
#include "EventFunc.h"

class CObj;

void AddObjEvt(CObj* _pObj);
void ChangeSceneEvt(SCENE_TYPE _eType);
void DeleteObjEvt(CObj* _pObj);