#ifndef _PB_H
#define _PB_H

class PBCLSigEntry
{
public:
	DWORD Code;            //0x00
	DWORD Offset;        //0x04
	//  WORD Type;            //0x08 
	char Type[2];   //0x08
	WORD Length;        //0x0A
	WORD Sig[128];     //0x0C
	DWORD Arg1;            //0x10C
	DWORD Arg2;            //0x110
	DWORD Arg3;            //0x114
	DWORD Enabled;      //0x118
	DWORD Arg5;            //0x11C

}; //0x120


char* GetSig(PBCLSigEntry *p)
{

	static char szSig[512];
	if(!p)return "   ";

	memset( (LPVOID)&szSig, 0, 512);

	int len  = p->Length;
	if(len>128)len = 128;
	for ( UINT i=0; i<len; i++ )
	{

		int iOffset = i * 2;
		int iBufSpace = 256 - iOffset;


		{
			if (p->Sig[i] > 0xFF)
				strcat_s( (char*)&szSig, 256, "??" );
			else
				sprintf_s( (char*)&szSig + iOffset, iBufSpace, "%02X", p->Sig[i] );
		}

	}

	return szSig;

}

template <class T>
class PBTable
{
public:
	T* m_pEntries;    
	DWORD m_Count;
	DWORD m_BytesPerEntry;
public:
	T* GetEntry( UINT Index )
	{
		if (Index >= m_Count) return NULL;
		return (T*)((DWORD)m_pEntries + ( Index * m_BytesPerEntry ));
	}
};

struct PBTABLE
{
	PBCLSigEntry* m_pEntries;    
	DWORD m_Count;
	DWORD m_BytesPerEntry;

	PBCLSigEntry *GetSig(UINT num)
	{
		if (num >= m_Count) return 0;
		return (PBCLSigEntry*)((DWORD)m_pEntries + ( num * m_BytesPerEntry ));
	}
};
#endif