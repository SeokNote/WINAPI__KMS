
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Isaac.h"
#include "ContentsEnums.h"
#include "Poop.h"



Poop::Poop()
{

}

Poop::~Poop()
{
}


void Poop::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Poop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Poop.bmp"));
	Poop->Cut(5, 1);

}

bool LoadPoop = true;
void Poop::Start()
{
	if (true == LoadPoop)
	{
		ImageLoad();
		LoadPoop = false;
	}
	PoopRender = CreateRender(IsaacRenderOrder::Object);
	PoopRender->SetScale({ 70, 70 });



	PoopRender->CreateAnimation({ .AnimationName = "Poop4",  .ImageName = "Poop.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	PoopRender->CreateAnimation({ .AnimationName = "Poop3",  .ImageName = "Poop.bmp", .Start = 1, .End = 1, .InterTime = 1.0f , .Loop = false });
	PoopRender->CreateAnimation({ .AnimationName = "Poop2",  .ImageName = "Poop.bmp", .Start = 2, .End = 2, .InterTime = 1.0f , .Loop = false });
	PoopRender->CreateAnimation({ .AnimationName = "Poop1",  .ImageName = "Poop.bmp", .Start = 3, .End = 3, .InterTime = 1.0f , .Loop = false });
	PoopRender->CreateAnimation({ .AnimationName = "Poop0",  .ImageName = "Poop.bmp", .Start = 4, .End = 4, .InterTime = 1.0f , .Loop = false });



	PoopRender->ChangeAnimation("Poop4");

	{

		PoopCol = CreateCollision(IsaacCollisionOrder::Poop);
		PoopCol->SetScale({ 50, 50 });
		PoopCol->On();
		PoopCol->SetDebugRenderType(CollisionType::CT_Rect);
	}

}


void Poop::Update(float _DeltaTime)
{

	CollisionCheck(_DeltaTime);
}

void Poop::CollisionCheck(float _DeltaTime)
{
	std::vector<GameEngineCollision*> PopCollisions;
	CollisionCheckParameter CheckPop = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };


	if (true == PoopCol->Collision(CheckPop, PopCollisions)) 
	{
		PopCollisions[0]->GetActor()->Death(); 

		PoopHp -= 1;
		if (4 == PoopHp)
		{
			PoopRender->ChangeAnimation("Poop4");
		}
		if (3 == PoopHp)
		{
			PoopRender->ChangeAnimation("Poop3");
		}
		if (2 == PoopHp)
		{
			PoopRender->ChangeAnimation("Poop2");
		}
		if (1 == PoopHp)
		{
			PoopRender->ChangeAnimation("Poop1");
		}
		if (0 == PoopHp)
		{
			PoopRender->ChangeAnimation("Poop0");
			PoopCol->Off();
		}
	}
}


void Poop::Render(float _DeltaTime)
{
	//Poop_Coll->DebugRender();
}