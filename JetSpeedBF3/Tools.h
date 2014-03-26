enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
#define INRANGE(x,a,b)    (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))
void GetModuleAddressAndSize(const char* dllName, DWORD* base, DWORD* size,HMODULE ModuleHandle=NULL) //zoomgod http://www.unknowncheats.me/forum/633534-post5.html
{

	MODULEINFO module;

	ZeroMemory(&module, sizeof(module));

	*base = 0;
	*size = 0;

	if(!ModuleHandle)
	{
		ModuleHandle=GetModuleHandleA(dllName);
	}
	if (GetModuleInformation(GetCurrentProcess(), ModuleHandle, &module, sizeof(module)))
	{
		*base = (DWORD)module.lpBaseOfDll;
		*size = (DWORD)module.SizeOfImage;
	}

}
DWORD FindPattern( DWORD rangeStart, DWORD rangeEnd, const char* pattern )//Learn_more
{
	const char* pat = pattern;
	DWORD firstMatch = 0;
	for( DWORD pCur = rangeStart; pCur < rangeEnd; pCur++ )
	{
		if( !*pat ) return firstMatch;
		if( *(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte( pat ) ) {
			if( !firstMatch ) firstMatch = pCur;
			if( !pat[2] ) return firstMatch;
			if( *(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?' ) pat += 3;
			else pat += 2;    //one ?
		} else {
			pat = pattern;
			firstMatch = 0;
		}
	}
	return NULL;
} 
//prints text in precolor then resets color and goes to newline
void SetConsoleColor(colour PreColor,colour PostColor,char* text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),PreColor);
	cout<<text<<"\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),PostColor);
}