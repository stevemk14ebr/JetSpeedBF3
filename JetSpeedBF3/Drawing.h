#include <ShlObj.h>
//uses screen coordinates
bool first=true;
float timer2=0;
clock_t current=clock();
clock_t previous=clock();
static fb::Vec3 Vec3Transform( fb::Vec3 In, fb::LinearTransform * pm )
{
	fb::Vec3 Out;

	Out.x = pm->left.x * In.x + pm->up.x * In.y + pm->forward.x * In.z + pm->trans.x;
	Out.y = pm->left.y * In.x + pm->up.y * In.y + pm->forward.y * In.z + pm->trans.y;
	Out.z = pm->left.z * In.x + pm->up.z * In.y + pm->forward.z * In.z + pm->trans.z;

	return Out;
}
BOOL Bf3W2S( fb::Vec3*world, fb::Vec3*screen )
{
	fb::GameRenderer* pGameRenderer=fb::GameRenderer::Singleton();
	if(!world || !screen || !pGameRenderer)
		return 0;
	BOOL ReturnValue;
	fb::LinearTransform *view = &pGameRenderer->m_viewParams.view.m_viewMatrix;
	fb::LinearTransform *projection = &pGameRenderer->m_viewParams.view.m_projectionMatrix;
	DWORD fb__projectToScreenSpace = 0x00765000;//also in math.worldtoplane
	__asm
	{
		push projection
			push view
			push world
			push screen
			call fb__projectToScreenSpace
			mov ReturnValue, eax
			pop eax
			pop eax
			pop eax
			pop eax
	}
	return ReturnValue; 
}
bool ProjectToScreen( fb::Vec3* world, fb::Vec3* out )//xCyniu
{
	fb::GameRenderer* pGameRenderer=fb::GameRenderer::Singleton();
	if(!world || !out || !pGameRenderer)
		return 0;
	fb::LinearTransform *view = &pGameRenderer->m_viewParams.view.m_viewMatrix;
	fb::LinearTransform *projection = &pGameRenderer->m_viewParams.view.m_projectionMatrix;
	return ((bool(__cdecl*)( fb::Vec3*, fb::LinearTransform*, fb::LinearTransform*, fb::Vec3*))0x764A90)( world, view, projection, out );
}
void Draw2dLine(fb::Vec3 ScreenPos1,fb::Vec3 ScreenPos2,fb::Color32 Color)
{
	fb::Tuple2<float>pos1=fb::Tuple2<float>(ScreenPos1.x,ScreenPos1.y);
	fb::Tuple2<float>pos2=fb::Tuple2<float>(ScreenPos2.x,ScreenPos2.y);
	fb::DebugRenderer2::Singleton()->drawLine2d(&pos1,&pos2,Color);
}
//uses screencoordinates
void Draw2dLineRect(fb::Vec3 ScreenPos1,fb::Vec3 ScreenPos2,fb::Color32 Color)
{
	fb::Tuple2<float>pos1=fb::Tuple2<float>(ScreenPos1.x,ScreenPos1.y);
	fb::Tuple2<float>pos2=fb::Tuple2<float>(ScreenPos2.x,ScreenPos2.y);
	fb::DebugRenderer2::Singleton()->drawLineRect2d(&pos1,&pos2,Color);
}
void CalcBox(fb::AxisAlignedBox* box2,fb::LinearTransform* trans,fb::Color32 color)
{
	__declspec(align(16)) fb::AxisAlignedBox box=*box2;
	fb::Vec3 max,min;
	fb::AxisAlignedBox boxwithtrans;
	boxwithtrans.max=Vec3Transform(box.max,trans);
	boxwithtrans.min=Vec3Transform(box.min,trans);

	/*Bf3W2S(&boxwithtrans.max,&max);
	Bf3W2S(&boxwithtrans.min,&min);*/
	ProjectToScreen(&boxwithtrans.max,&max);
	ProjectToScreen(&boxwithtrans.min,&min);
	Draw2dLineRect(min,max,color);
}
void Draw2dBoundingBox(fb::ClientPlayer* pClientPlayer)
{
	fb::AxisAlignedBox box,boxwithtrans;
	fb::Vec3 max,min;
	
	pClientPlayer->m_soldier.GetData()->m_characterPhysicsentity->getLocalBoundingBoxForPose(&box,pClientPlayer->m_soldier.GetData()->m_character->pose(),false);
	CalcBox(&box,pClientPlayer->m_soldier.GetData()->m_characterPhysicsentity->m_gameWorldTransform,fb::Color32::Blue());	
}
//use screencoordinates
void DrawSnapLine(fb::Vec3 target,fb::Color32 Color)
{
	fb::Vec3 linestart;
	float height=fb::DxRenderer::Singleton()->m_screenInfo.m_nHeight;
	linestart.x = fb::DxRenderer::Singleton()->m_screenInfo.m_nWidth / 2;
	linestart.y = height-(height*.05f);

	Draw2dLine(target,linestart,Color);
}
void _stdcall Bulletesp()
{
	fb::ClientGameContext* p_gameconext=fb::ClientGameContext::Singleton();
	if(!POINTERCHK(p_gameconext)) return;

	fb::EntityWorld::EntityCollection Entity = p_gameconext->m_level->m_gameWorld->m_collections.at(252);
	if(Entity.firstSegment) 
	{ 
		for( int i = 0; i < (int)Entity.firstSegment->m_Collection.size(); i++) 
		{ 
			if(Entity.firstSegment->m_Collection.size() > 0) 
			{ 
				fb::GameEntity* pEntity = reinterpret_cast< fb::GameEntity* >(Entity.firstSegment->m_Collection.at(i)); 
				if(!POINTERCHK(pEntity))
					return;

				fb::Vec3* bullet=pEntity->GetEntityOrigin();
				
			
				fb::DebugRenderer::Singleton()->DrawSphere(*bullet,.125f,fb::Color32::Green(),true,false);
				
			}
		}
	}
}
void _stdcall DrawTime()
{

	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	
	timeinfo = localtime(&rawtime);
	fb::DebugRenderer2::Singleton()->drawText(0,20,fb::Color32::Red(),asctime(timeinfo),1);  
}