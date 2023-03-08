
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
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
	RockRender = CreateRender(IssacRenderOrder::Object);
	RockRender->SetScale({ 70, 70 });


	RockRender->CreateAnimation({ .AnimationName = "Rock_On",  .ImageName = "Rock.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	RockRender->CreateAnimation({ .AnimationName = "Rock_Break",  .ImageName = "Rock.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });



	RockRender->ChangeAnimation("Rock_On");

	{

		RockCol = CreateCollision(IssacCollisionOrder::Rock);
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
	CollisionCheckParameter CheckRock = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IssacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };


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