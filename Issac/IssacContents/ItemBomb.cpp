
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"

#include "ItemBomb.h"



ItemBomb::ItemBomb()
{

}

ItemBomb::~ItemBomb()
{
}


void ItemBomb::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* ItemBomb = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ItemBomb.bmp"));
	ItemBomb->Cut(6, 6);

}

bool LoadItemBomb = true;

void ItemBomb::Start()
{
	if (true == LoadItemBomb)
	{
		ImageLoad();
		LoadItemBomb = false;
	}
	ItemBombRender = CreateRender(IssacRenderOrder::Object);
	ItemBombRender->SetScale({ 65, 65 });

	ItemBombRender->CreateAnimation({ .AnimationName = "ItemBomb",  .ImageName = "ItemBomb.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	ItemBombRender->ChangeAnimation("ItemBomb");
	{
		ItemBombCol = CreateCollision(IssacCollisionOrder::ItemBomb);
		ItemBombCol->SetScale({ 10, 10 });
		ItemBombCol->On();
		ItemBombCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemBomb::Update(float _DeltaTime)
{

}

void ItemBomb::Render(float _DeltaTime)
{
	//ItemBombCol->DebugRender();
}