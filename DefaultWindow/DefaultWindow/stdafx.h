// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

#include <Ole2.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;
// C ��Ÿ�� ��� �����Դϴ�.


#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "targetver.h"


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
using namespace std;

#include <iostream>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#include <cmath>

#include "Define.h"
#include "Enum.h"
#include "Enum_String.h"
#include "Struct.h"
#include "Template.h"
#include "ASCII.h"
#include "CustomFunc.h"
#include "SelectGDI.h"


#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif