#pragma once

#define			WINCX		800
#define			WINCY		600

#define			PURE		= 0

#define			OBJ_NOEVENT  0
#define			OBJ_EVENT	 1
#define			PI			 3.141592f

#define			SAFE_DELETE(type) if(type != nullptr) delete type; type = nullptr;


#pragma region Singleton
#define SINGLETON(type)\
public:\
	static type* GetInst()\
	{\
		static type manager;\
		return &manager;\
	}\
private:\
	type();\
	~type();
#pragma endregion Singleton

#define CLONE(type) type* Clone() { return new type(*this); }
#define NOT_CLONE(type) type* Clone() = delete;

extern HWND	g_hWnd;