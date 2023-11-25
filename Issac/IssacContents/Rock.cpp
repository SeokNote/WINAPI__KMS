
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "ContentsEnums.h"
#include "Rock.h"




Rock::Rock()
{

}

Rock::~Rock()
{
}


void Rock::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Rocks = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Rock.bmp"));
	Rocks->Cut(4, 8);

}

bool LoadRock = true;

void Rock::Start()
{
	if (true == LoadRock)
	{
		ImageLoad();
		LoadRock = false;
	}
	RockRender = CreateRender(IsaacRenderOrder::Object);
	RockRender->SetScale({ 70, 70 });


	RockRender->CreateAnimation({ .AnimationName = "Rock_On",  .ImageName = "Rock.bmp", .Start = 4, .End = 4, .InterTime = 1.0f , .Loop = false });
	RockRender->CreateAnimation({ .AnimationName = "Rock_Break",  .ImageName = "Rock.bmp", .Start = 7, .End = 7, .InterTime = 1.0f , .Loop = false });



	RockRender->ChangeAnimation("Rock_On");

	{

		RockCol = CreateCollision(IsaacCollisionOrder::Rock);
		RockCol->SetScale({ 50, 50 });
		RockCol->On();
		RockCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void Rock::Update(float _DeltaTime)
{
	Render(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Rock::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> RCollisions;
	CollisionCheckParameter CheckRock = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };


	if (true == RockCol->Collision(CheckRock, RCollisions)) //ÆøÅº¿¡´êÀ¸¸é
	{
		RockRender->ChangeAnimation("Rock_Break");
		RockCol->Off();
	}
	if (true == RockCol->Collision(CheckAttack, RCollisions)) //ÇÃ·¹ÀÌ¾î°ø°ÝÀÌ´êÀ¸¸é
	{
		RCollisions[0]->GetActor()->Death();
	}
}

void Rock::MoveCalculation(float _DeltaTime)
{
}

void Rock::Render(float _DeltaTime)
{
}