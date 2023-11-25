
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "ContentsEnums.h"
#include "BombRock.h"

#include "ItemBomb.h"




BombRock::BombRock()
{

}

BombRock::~BombRock()
{
}


void BombRock::ImageLoad()
{/*
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Rock_Boom = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rock.bmp"));
	Rock_Boom->Cut(4, 8);*/

}

void BombRock::Start()
{

	BombRockRender = CreateRender(IsaacRenderOrder::Object);
	BombRockRender->SetScale({ 70, 70 });


	BombRockRender->CreateAnimation({ .AnimationName = "BombRock",  .ImageName = "Rock.bmp", .Start = 8, .End = 8, .InterTime = 1.0f , .Loop = false });
	BombRockRender->CreateAnimation({ .AnimationName = "BombRockBreaks",  .ImageName = "Rock.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });

	BombRockRender->ChangeAnimation("BombRock");

	{

		BombRockCol = CreateCollision(IsaacCollisionOrder::Rock);
		BombRockCol->SetScale({ 50, 50 });
		BombRockCol->On();
		BombRockCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void BombRock::Update(float _DeltaTime)
{
	Render(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

bool DropItemBomb = true;

void BombRock::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> RCollisions;
	CollisionCheckParameter CheckBombRock = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == BombRockCol->Collision(CheckBombRock, RCollisions)) //ÆøÅº¿¡´êÀ¸¸é
	{
		if (true == DropItemBomb)
		{
			BombRockRender->ChangeAnimation("BombRockBreaks");
			ItemBomb* RockItem = GetLevel()->CreateActor<ItemBomb>(IsaacRenderOrder::Object);
			RockItem->SetPos(GetPos());
			BombRockCol->Off();
			DropItemBomb = false;
		}
	}
	if (true == BombRockCol->Collision(CheckAttack, RCollisions)) //ÇÃ·¹ÀÌ¾î°ø°ÝÀÌ´êÀ¸¸é
	{
		RCollisions[0]->GetActor()->Death();
	}
}

void BombRock::Render(float _DeltaTime)
{

}