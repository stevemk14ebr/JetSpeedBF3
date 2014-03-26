#define _USE_MATH_DEFINES
#include <cmath>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

#include "FB SDK\Frostbite.h"

#include "VMTHook.h"

#include "FB SDK/CharacterPhysicsEntityCollisionShapes.h"
#include "Tools.h"
#include "PB.h"
#include "FixedVector.h"
#include "Drawing.h"
#include "Functions.h"
#include "VehicleData.h"


using namespace std;
void* operator new[](size_t size, const char* pName, int flags,unsigned debugFlags, const char* file, int line)
{
	return malloc(size);
}
void* operator new[](size_t size, size_t alignment, size_t alignmentOffset, const char* pName, int flags, unsigned debugFlags, const char* file, int line)
{
	EASTL_ASSERT(alignment <= 8);
	return malloc(size);
}

CVMTHookManager* PresentHook = 0;
typedef signed int ( __stdcall* tPresent )( int, int, int );
tPresent oPresent; //our dx hook

bool scanonce=true;

HMODULE Handle; //module handle

void _stdcall Draw()
{
	
	fb::ClientGameContext* g_pGameContext = fb::ClientGameContext::Singleton();
    if (!POINTERCHK(g_pGameContext))
        return;

    fb::ClientPlayerManager* pPlayerManager = g_pGameContext->m_clientPlayerManager;
    if(!POINTERCHK(pPlayerManager) || pPlayerManager->m_players.empty()) 
        return;
	
    fb::ClientPlayer* pLocalPlayer = pPlayerManager->m_localPlayer;
    if (!POINTERCHK(pLocalPlayer))
        return;

	fb::ServerPlayer* pLocalServerPlayer=reinterpret_cast< fb::ServerPlayer * >(pLocalPlayer);
	if (pLocalServerPlayer && !pLocalServerPlayer->m_isIngame ) return;

    fb::ClientSoldierEntity* pMySoldier = pLocalPlayer->getSoldierEnt();
    if (!POINTERCHK(pMySoldier))
        return;
	
	if (!isalive(pMySoldier->Alive()))
        return;
	
	if(pMySoldier->isInVehicle())
	{
		if(getVehicleType(pLocalPlayer))
		{
			fb::Vec3 speed=getVehicleSpeed(pMySoldier);
			char output[1024];
			sprintf(output,"%f",speed.VectorLength()*3.6);
			fb::DebugRenderer2::Singleton()->drawText(0,40,fb::Color32::Red(),output,1);
		}
		
	}
	
	DrawTime();
}


signed int __stdcall hkPresent( int a1, int a2, int a3 )
{
		__asm pushad;
	
		*(DWORD*)0x0235DB14 = 0.0; //zero out pbss
		fb::DebugRenderer2::Singleton()->drawText(0,0,fb::Color32::Red(),"JetSpeed Injected",1);
		Draw();
		if(GetAsyncKeyState(0x4C) || scanonce)
		{
			pbsigs(PresentHook,Handle);
			scanonce=false;
			Sleep(500);
		}
		__asm popad;

	return oPresent( a1, a2, a3 );
}
BOOL WINAPI DllMain (HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
    if (dwAttached == DLL_PROCESS_ATTACH) {
		Handle=hModule;
		DisableThreadLibraryCalls(hModule);
		
		PresentHook = new CVMTHookManager( ( DWORD** )fb::DxRenderer::Singleton()->pSwapChain );//initialize hook manager with swapchain address
		oPresent = ( tPresent )PresentHook->dwGetMethodAddress( 8 );//save old address
		PresentHook->dwHookMethod( ( DWORD )hkPresent, 8 );//hook it
		
		CreateConsole();
		
		
	   }
    return 1;
}
