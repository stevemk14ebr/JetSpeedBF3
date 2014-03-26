#include <ShlObj.h>
template<typename T, std::size_t N>
std::size_t array_size(T (&)[N]) {
	return N;
}
void _stdcall pbsigs(CVMTHookManager* PresentHook,HMODULE ModuleHandle=NULL)
{
	PBTABLE *pSigs = (PBTABLE*)((DWORD)GetModuleHandleA("pbcl.dll") + 0xAD6B4);
	DWORD Base,Size; //get base and size of our dll module
	GetModuleAddressAndSize("Public.dll",&Base,&Size,ModuleHandle); //we are passing module handle so the name is ignored
	for ( UINT i=0; i<pSigs->m_Count; i++)
	{
		PBCLSigEntry* pSig = pSigs->GetSig(i);
		if (pSig )
		{  		
			//Start scanning for the sig
			if(strlen(GetSig(pSig))<=5) //don't want to scan on an empty sig
			continue;

			/* Test FindPattern to see if it exits on hit, this pattern hits in dllmain
			A1 ? ? ? ? 8B CE */
			
			DWORD Address=FindPattern(Base,Base+Size,GetSig(pSig));
			if(Address) //if not null, pattern hit
			{
				char output[120];
				sprintf_s(output,"Found Match at %d Sig: [ %s ]",i,GetSig(pSig));
				SetConsoleColor(colour::RED,colour::GRAY,output);
				ofstream myfile;
				char path[MAX_PATH];
				SHGetFolderPath(NULL,CSIDL_DESKTOPDIRECTORY,0,NULL,path); //get desktop folder
				strcat(path,"\\Match_Found.txt");//add Sigs.text to path
				myfile.open (path,ios::trunc|ios::out);
				myfile<<output<<"\n";
				myfile<<"This bf3 hack by stevemk14ebr has been detected and has automatically closed your game, please notify stevemk14ebr on Unknowncheats.me for an update \n";
				myfile.close();
				PresentHook->UnHook();
				ExitProcess(0);
			}else{
				cout<<"Sig Index: "<<i;
				SetConsoleColor(colour::GREEN,colour::GRAY," :No Match");
			}
		}	
	}
	printf("Scanned %d Sigs 0x%X to 0x%X No Matches: ",pSigs->m_Count,Base,Base+Size);
	SetConsoleColor(colour::GREEN,colour::GRAY,"Undetected");
}
bool isalive(int i)
{
	if(i == 34271745)
		return true;
	else if(i == 34272001)
		return true;
	else if(i == 34272257)
		return true;
	return false;
}

VOID CreateConsole( )
{
	int hConHandle = 0; 
	HANDLE lStdHandle = 0;
	FILE *fp = 0;
	AllocConsole( );
	lStdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
	hConHandle = _open_osfhandle( PtrToUlong( lStdHandle ), _O_TEXT );
	fp = _fdopen( hConHandle, "w" );
	*stdout = *fp;
	setvbuf( stdout, NULL, _IONBF, 0 );
}  
fb::ClientVehicleEntity* GetVehicle(fb::ClientPlayer* pClientPlayer)
{
	fb::ClientControllableEntity* pControllable=pClientPlayer->m_attachedControllable;
	if(!POINTERCHK(pControllable))
		return NULL;

	fb::ClientVehicleEntity* pVehicle=reinterpret_cast<fb::ClientVehicleEntity*>(pControllable);
	if(!POINTERCHK(pVehicle))
		return NULL;

	return pVehicle;
}


