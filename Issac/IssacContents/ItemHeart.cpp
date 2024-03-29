
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "ContentsEnums.h"

#include "ItemHeart.h"



ItemHeart::ItemHeart()
{

}

ItemHeart::~ItemHeart()
{
}

// 관련된건 Isaac.cpp에서관리
void ItemHeart::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	GameEngineImage* Heart = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Heart.bmp"));
	Heart->Cut(3, 6);
}

bool Load = true;
void ItemHeart::Start()
{
	if (true == Load)
	{
		ImageLoad();
		Load = false;
	}
	HeartRender = CreateRender(IsaacRenderOrder::Object);
	HeartRender->SetScale({ 70, 70 });
	
	HeartRender->CreateAnimation({ .AnimationName = "Heart",  .ImageName = "Heart.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	HeartRender->ChangeAnimation("Heart");

	{
		HeartCol = CreateCollision(IsaacCollisionOrder::ItemHeart);
		HeartCol->SetScale({ 10, 10 });
		HeartCol->On();
		HeartCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemHeart::Update(float _DeltaTime)
{

}

void ItemHeart::Render(float _DeltaTime)
{
	//HeartCol->DebugRender();
}