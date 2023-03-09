
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"
#include "STone.h"




STone::STone()
{

}

STone::~STone()
{
}


void STone::ImageLoad()
{


}

bool LoadStone = true;

void STone::Start()
{
	if (true == LoadStone)
	{
		ImageLoad();
		LoadStone = false;
	}
	SToneRender = CreateRender(IssacRenderOrder::Object);
	SToneRender->SetScale({ 70, 70 });


	SToneRender->CreateAnimation({ .AnimationName = "Rock_On",  .ImageName = "Rock.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	SToneRender->CreateAnimation({ .AnimationName = "Rock_Break",  .ImageName = "Rock.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });



	SToneRender->ChangeAnimation("Rock_On");

	{

		SToneCol = CreateCollision(IssacCollisionOrder::Rock);
		SToneCol->SetScale({ 50, 50 });
		SToneCol->On();
		SToneCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}


void STone::Update(float _DeltaTime)
{
	Render(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void STone::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> RCollisions;
	CollisionCheckParameter CheckSTone = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IssacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };


	if (true == SToneCol->Collision(CheckSTone, RCollisions)) //ÆøÅº¿¡´êÀ¸¸é
	{
		SToneRender->ChangeAnimation("Rock_Break");
		SToneCol->Off();
	}
	if (true == SToneCol->Collision(CheckAttack, RCollisions)) //ÇÃ·¹ÀÌ¾î°ø°ÝÀÌ´êÀ¸¸é
	{
		RCollisions[0]->GetActor()->Death();
	}
}

void STone::MoveCalculation(float _DeltaTime)
{
}

void STone::Render(float _DeltaTime)
{
}