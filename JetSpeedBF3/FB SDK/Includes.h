#ifndef __INCLUDES__H_
#define __INCLUDES__H_

#pragma once

#pragma warning (disable:4099) //  type name first seen using 'class' now seen using 'struct'
#pragma warning (disable:4244) // '+=' : conversion from 'int' to 'WORD', possible loss of data
#pragma warning (disable:4305) // truncation from 'double' to 'float
#pragma warning (disable:4800) //forcing value to bool 'true' or 'false'
#pragma comment(lib, "Winmm.lib" )
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib,"d3dx10.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")


//#pragma comment(lib,"ntdll.lib")


#define WIN32_LEAN_AND_MEAN
#define __DEBUG_LOG__ // Comment to disable debug logging.


#include <windows.h>
#include <TlHelp32.h>
//#include "<stdafx.h>"
#include <d3d11.h>
#include <d3d9.h>
#include <d3dx9math.h>
#include <d3dx10.h>
#include <intrin.h>
#include <ddraw.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <tchar.h>
#include <vector>
#include <strstream>
#include <iomanip>
#include <math.h>
#include <LMCons.h>
#include <process.h>  
#include <time.h> 
#include "psapi.h"
#include <tlhelp32.h>
#include <sstream>
#include <Shellapi.h>
#include <tchar.h>
#include <stddef.h> 
#include <Vector>
#include <TCHAR.H>

using namespace std;


//#include "Singleton.h"
//#include "Logwriter.h"

#define CONCAT_IMPL(x, y) x##y
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)
#define PAD(SIZE) BYTE MACRO_CONCAT(_pad, __COUNTER__)[SIZE];
#define POINTERCHK( pointer ) ( pointer  && pointer !=0  && HIWORD( pointer ) )

#endif