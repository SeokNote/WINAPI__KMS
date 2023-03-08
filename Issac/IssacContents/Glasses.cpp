#include "Glasses.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "ContentsEnums.h"
#include "issac.h"



Glasses::Glasses()
{

}

Glasses::~Glasses()
{

}

bool LoadImage1 = true;
void Glasses::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Items");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Glasses.BMP"));
}

void Glasses::Start()
{
	if (true == LoadImage1)
	{
		ImageLoad();
		LoadImage1 = false;
	}
	// 兄希 持失
	{
		GlassesRender = CreateRender(IssacRenderOrder::Object);
		GlassesRender->SetScale({ 60, 60 });
		GlassesRender->SetImage("Item_Glasses.BMP");
	}
	//Colliison持失
	{
		GlassesCol = CreateCollision(IssacCollisionOrder::ItemGlasses);
		GlassesCol->SetScale({ 30,30 });
		GlassesCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Glasses::Update(float _DeltaTime)
{

}


void Glasses::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
