#include "Leo.h"
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



Leo::Leo()
{

}

Leo::~Leo()
{

}

bool LoadImage2 = true;
void Leo::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Items");

	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Item_Leo.BMP"));
}

void Leo::Start()
{
	if (true == LoadImage2)
	{
		ImageLoad();
		LoadImage2 = false;
	}
	// 兄希 持失
	{
		LeoRender = CreateRender(IsaacRenderOrder::Object);
		LeoRender->SetScale({ 60, 60 });
		LeoRender->SetImage("Item_Leo.BMP");
	}
	//Colliison持失
	{
		LeoCol = CreateCollision(IsaacCollisionOrder::ItemLeo);
		LeoCol->SetScale({ 30,30 });
		LeoCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void Leo::Update(float _DeltaTime)
{

}


void Leo::Render(float _DeltaTime)
{
	//LeoCollision->DebugRender();
}
