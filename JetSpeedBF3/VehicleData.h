
struct stMyVehicle 
{
	char* m_Game_Name;
	float m_Distance;
	int m_WeaponEntryPoint;
	bool m_ValidWeapon;
	bool m_IsRepairable;
	bool m_AltAimActive;
	bool m_CanBeTuned;
	bool m_CanHitPlayer;
	bool m_CanHitArmor;
	bool m_CanHitPlane;
	bool m_CanHitHeli;
	bool m_IsHeli;
	bool m_IsJet;
	bool m_HasOpenSeats;
	bool m_CanAutoLaser;
};
static stMyVehicle VEHICLEDATA[39] = {
	//Helicopters
	//pilot is 0 no attach + control  passenger is attach 1-3 no control
	{"AH6", 600.f, 0, true, true, true, true, true, true, true, true, true, false, true, false},
	//pilot is 0 no attach + control  passenger is attach 1-3 no control
	{"Z11W", 600.f, 0, true, true, true, true, true, true, true, true, true, false, true, false},


	//0 or 1 (300) or 4 (350)    gunner is 1   + attach a control @ weaponstate 4 = tvmissile?
	{"AH1Z", 600.f, 1, true, false, true, true, true, true, true, true, true, false, false, false},
	//0 or 1 (300) or 4 (350)    gunner is 1   + attach a control @ weaponstate 4 = tvmissile?
	{"Mi28", 600.f, 1, true, false, true, true, true, true, true, true, true, false, false, false},

	//  Gunner is 0 + attach a control
	{"Venom", 400.f, 0, false, true, false, true, true, false, true, true, true, false, true, false},
	//  Gunner is 0 + attach a control
	{"KA-60", 400.f, 0, false, true, false, true, true, false, true, true, true, false, true, false},		

	//Jets 
	//is 0
	{"SU-35BM-E",1200.f, 0, true, false, true, true, true, true, true, true, false, true, false, false},
	//is 0
	{"F18-F", 1200.f, 0, true, false, true, true, true, true, true, true, false, true, false, false},
	//is 0
	{"F35", 1200.f, 0, true, false, true, true, true, true, true, true, false, true, false, false},
	//need to look but i would guess its 0
	{"SU-25TM", 1200.f, 0, true, false, true, true, true, true, true, true, false, true, false, false},
	{"A-10", 1200.f, 0, true, false, true, true, true, true, true, true, false, true, false, false},
	//AntiAir
	//is 0 no attach a control
	{"9K22", 1100.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	{"Centurion",1100.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	{"Centurion_CRam", 1100.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	{"Pantsir", 1100.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	//GunsHip

	//attch+control 01 is 0 (600) 25mm cannon and 1 (900) attach+control 2 is 1 (900) 250 is apshell
	{"ac130", 1000.f, 1, true, false, false, true, true, true, true, true, false, false, false, false},
	//Main Battle Tanks
	// 0 as driver + 4 is shells Gunner is 0 + attach a control
	{"M1A2",  800.f, 0, true, false, true, true, true, true, true, true, false, false, false, true},
	// 0 as driver + 2 is shells Gunner is 0 + attach a control
	{"T90", 800.f, 0, true, false, true, true, true, true, true, true, false, false, false, true},
	// 2 as driver + 3 is shells not attach + control   0 as passenger with gun plus attach + control 1-4
	{"2S25-SPRUT-SD", 800.f, 2, true, false, true, true, true, true, true, true, false, false, false, false},
	// 3 as driver + 4 is shells not attach + control   0 as passenger with gun plus attach + control 1-4
	{"M1128-Stryker", 800.f, 3, true, false, true, true, true, true, true, true, false, false, false, false},
	//other Tanks
	// 2 as driver no attach a control  0 as gunner plus attach + control 1  0 as passenger with gun plus attach + control 2-5
	{"BMP2",  800.f, 2, true, false, true, true, true, true, true, true, false, false, false, false},
	// 2 as driver Gunner is 0 + attach a control		0 as passenger with gun plus attach + control 2-5
	{"BTR-90", 800.f, 2, true, false, true, true, true, true, true, true, false, false, false, false},
	// 2 as driver   0 as gunner plus attach + control 1   0 as passenger with gun plus attach + control 2-5
	{"LAV25", 800.f, 2, true, false, true, true, true, true, true, true, false, false, false, false},



	//Rocket Launchers Mobile Himars and STAR
	{"STAR",  800.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	{"HIMARS", 800.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	//Armored or modified Personel Carrier
	//
	{"AAV-7A1",  400.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},		


	//driver nothing gunner: is 0 + attach a control  passenger 2+3 is only  m_attachedEntryId  
	{"HumveeArmored", 500.f, 0, true, false, false, true, true, false, true, true, false, false, false, false},
	//driver is 0 no attach + controll gunner: is 0 + attach1 a control1 (grav is 15)  nademan is control + attach 2
	{"HumveeModified", 500.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},
	//driver is 0 no attach + controll  passsenger is 1-3 with attach no control
	{"VanModified", 500.f, 0, true, true, true, true, true, false, true, true, false, false, true, false},
	//driver nothing gunner: is 0 + attach a control  passenger 2+3 is only  m_attachedEntryId  
	{"GAZ-3937",  800.f, 0, true, false, false, true, true, false, true, true, false, false, false, false},
	//driver is 0 no attach + controll nademan is  attach1 a control1 (grav is 10 wrong)   gunener is 0 and control + attach 2 ()
	{"VodnikModified", 800.f, 0, true, false, true, true, true, true, true, true, false, false, false, false},


	//Jeeps Boats
	//Gunner is 0 + attach a control	passenger 2 is only  m_attachedEntryId    
	{"DPV",  400.f, 0, false, true, true, true, true, false, true, true, false, false, false, false},
	//Gunner is 0 + attach a control	 passenger 2  is only  m_attachedEntryId    
	{"GrowlerITV",  400.f, 0, false, true, true, true, true, false, true, true, false, false, false, false},
	//Gunner is 0 + attach a control	 passenger 2  is only  m_attachedEntryId    
	{"VDV", 400.f, 0, false, true, true, true, true, false, true, true, false, false, false, false},
	//Gunner is 0 + attach a control	 passenger 2+3 is only  m_attachedEntryId    
	{"RHIB",  400.f, 0, false, true, false, true, true, false, true, true, false, false, false, false},

	//Vehicles without weapons
	{"QuadBike", 0.f, 0, false, false, false, false, true, false, false, false, false, false, true, false},
	{"SkidLoader", 0.f, 0, false, false, false, false, true, false, false, false, false, false, true, false},
	//Stationary Rocket Launchers
	{"Kornet", 800.f, 0, true, false, true, false, true, true, true, true, false, false, true, false},
	{"TOW2",  800.f, 0, true, false, true, false, true, true, true, true, false, false, true, false},
};
stMyVehicle* GetVehicleValues(char* szName)
{
	if (szName == NULL) 
		return 0;

	for (int i = 0; i < 39; i++) 
	{
		stMyVehicle* pVehicleValues = &VEHICLEDATA[i];
		if (strstr(pVehicleValues->m_Game_Name, szName))
			return pVehicleValues;
	}
	return 0;
}
//return 1 if jet,0 if heli
int getVehicleType(fb::ClientPlayer* ClientPlayer)
{
	fb::ClientControllableEntity *pCCE = ClientPlayer->m_attachedControllable; 
	if (!POINTERCHK(pCCE)) return 3;

	fb::ClientVehicleEntity* MyVehicle = reinterpret_cast< fb::ClientVehicleEntity * >(pCCE); 
	if(!POINTERCHK(MyVehicle)) return 3;

	fb::PhysicsEntity *pPE = MyVehicle->m_physicsEntity;
	if(!POINTERCHK(pPE)) return 3;

	fb::PhysicsEntityData *pPED = pPE->m_data;
	if(!POINTERCHK(pPED)) return 3;

	char *name = pPED->GetObjectName();

	int bImAHeli		=	GetVehicleValues(name)->m_IsHeli;
	int bImaJet			=	GetVehicleValues(name)->m_IsJet;

	if(bImaJet)
	{
		return 1;
	}
	if(bImAHeli)
	{
		return 0;
	}
}
fb::FiringFunctionData* GetVehicleFFD(fb::ClientPlayer* ClientPlayer)
{
	fb::ClientControllableEntity *pCCE = ClientPlayer->m_attachedControllable; 
	if (!POINTERCHK(pCCE)) return NULL;

	fb::ClientVehicleEntity* MyVehicle = reinterpret_cast< fb::ClientVehicleEntity * >(pCCE); 
	if(!POINTERCHK(MyVehicle)) return NULL;

	fb::PhysicsEntity *pPE = MyVehicle->m_physicsEntity;
	if(!POINTERCHK(pPE)) return NULL;

	fb::PhysicsEntityData *pPED = pPE->m_data;
	if(!POINTERCHK(pPED)) return NULL;

	char *name = pPED->GetObjectName();
	//GetVehicleValues(name)->m_WeaponEntryPoint

	fb::EntryComponent *entry=ClientPlayer->getEntry();
	if(!POINTERCHK(entry))
		return NULL;

	fb::EntryComponent::FiringCallbacks* pFC=entry->m_weapons.at(entry->getActiveStance());
	if(!POINTERCHK(pFC))
		return NULL;

	fb::WeaponInfo *WepInfo=pFC->m_info;
	if(!POINTERCHK(WepInfo))
		return NULL;

	fb::WeaponFiring* WepFiring=WepInfo->weaponFiring();
	if(!POINTERCHK(WepFiring))
		return NULL;

	fb::WeaponFiringData* WepFiringData=WepFiring->m_data;
	if(!POINTERCHK(WepFiringData))
		return NULL;

	fb::FiringFunctionData* FFD=WepFiringData->m_primaryFire;
	if(!POINTERCHK(FFD))
		return NULL;

	return FFD;

}
fb::PhysicsEntity* GetPhysicsEntity(fb::ClientPlayer* pClientPlayer)
{
	fb::ClientVehicleEntity* pVehicle=GetVehicle(pClientPlayer);
	if(!POINTERCHK(pVehicle))
		return NULL;

	fb::PhysicsEntity* pPhysEnt=pVehicle->m_physicsEntity;
	if(!POINTERCHK(pPhysEnt))
		return NULL;

	return pPhysEnt;
}
fb::Vec3 getVehicleSpeed(fb::ClientSoldierEntity * soldier)
{
	fb::Vec3 tempvec;
	if(soldier->m_player->m_attachedControllable)
	{
		tempvec	=*soldier->m_player->m_attachedControllable->getVehicleSpeed();
	}else{
		tempvec.x=0.0f;
		tempvec.y=0.0f;
		tempvec.z=0.0f;
	}
	return tempvec;
}