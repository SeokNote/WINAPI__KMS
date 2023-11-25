#include "Heart.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "ContentsEnums.h"
#include "Isaac.h"



Heart::Heart()
{

}

Heart::~Heart()
{

}

bool LoadImage3 = true;
void Heart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Items");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Heart.BMP"));
}

void Heart::Start()
{
	if (true == LoadImage3)
	{
		ImageLoad();
		LoadImage3 = false;
	}
	// 兄希 持失
	{
		HeartRender = CreateRender(IsaacRenderOrder::Object);
		HeartRender->SetScale({ 60, 60 });
		HeartRender->SetImage("Item_Heart.BMP");
	}
	//Colliison持失
	{
		HeartCol = CreateCollision(IsaacCollisionOrder::Heart);
		HeartCol->SetScale({ 30,30 });
		HeartCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Heart::Update(float _DeltaTime)
{

}


void Heart::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
