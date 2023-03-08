
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"
#include "Bomb.h"



Bomb::Bomb()
{

}

Bomb::~Bomb()
{
}


void Bomb::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Bomb = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bomb.bmp"));
	Bomb->Cut(3, 1);
	GameEngineImage* Bomb_Effect = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Bomb_Effect.bmp"));
	Bomb_Effect->Cut(4, 3);

}
bool LoadBomb = true;
void Bomb::Start()
{
	if (true == LoadBomb)
	{
		ImageLoad();
		LoadBomb = false;
	}
	BombRender = CreateRender(IssacRenderOrder::Player);
	BombRender->SetScale({ 70, 70 });
	SetPos(Issac::MainPlayer->GetPos());

	BombRender->CreateAnimation({ .AnimationName = "Bomb",  .ImageName = "Bomb.bmp", .Start = 0, .End = 2, .InterTime = 0.5f , .Loop = false });
	BombRender->CreateAnimation({ .AnimationName = "Bomb_Effect",  .ImageName = "Bomb_Effect.bmp", .Start = 0, .End = 11, .InterTime = 0.02f , .Loop = false });
	BombRender->ChangeAnimation("Bomb");

	{
		BombCol = CreateCollision(IssacCollisionOrder::Bomb);
		BombCol->SetScale({ 30, 30 });
		BombCol->Off();
		BombCol->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void Bomb::Update(float _DeltaTime)
{
	NowTime += _DeltaTime;
	BlinkSet(_DeltaTime);
	if (NowTime > 2.0f)
	{

		BombCol->On();
		BombRender->SetScale({ 200, 200 });
		BombCol->SetScale({ 100, 100 });
		BombRender->ChangeAnimation("Bomb_Effect");
	}
	if (NowTime > 2.1f)
	{	
		Death();
	}
}

void Bomb::BlinkSet(float _DeltaTime)
{
	BlinkTime += _DeltaTime;


	if (BlinkTime > 0.6f) { BombRender->Off(); }
	if (BlinkTime > 0.65f) { BombRender->On(); }
	if (BlinkTime > 0.7f) { BombRender->Off(); }
	if (BlinkTime > 0.75f) { BombRender->On(); }
	if (BlinkTime > 0.8f) { BombRender->Off(); }
	if (BlinkTime > 0.85f) { BombRender->On(); }
	if (BlinkTime > 0.9f) { BombRender->Off(); }
	if (BlinkTime > 0.95f) { BombRender->On(); }
	if (BlinkTime > 1.0f) { BombRender->Off(); }
	if (BlinkTime > 1.05f) { BombRender->On(); }
	if (BlinkTime > 1.1f) { BombRender->Off(); }
	if (BlinkTime > 1.15f) { BombRender->On(); }
	if (BlinkTime > 1.2f) { BombRender->Off(); }
	if (BlinkTime > 1.25f) { BombRender->On(); }
	if (BlinkTime > 1.3f) { BombRender->Off(); }
	if (BlinkTime > 1.35f) { BombRender->On(); }
	if (BlinkTime > 1.4f) { BombRender->Off(); }
	if (BlinkTime > 1.45f) { BombRender->On(); }
	if (BlinkTime > 1.5f) { BombRender->Off(); }
	if (BlinkTime > 1.55f) { BombRender->On(); }
	if (BlinkTime > 1.6f) { BombRender->Off(); }
	if (BlinkTime > 1.65f) { BombRender->On(); }
	if (BlinkTime > 1.7f) { BombRender->Off(); }
	if (BlinkTime > 1.75f) { BombRender->On(); }
	if (BlinkTime > 1.8f) { BombRender->Off(); }
	if (BlinkTime > 1.85f) { BombRender->On(); }
	if (BlinkTime > 1.9f) { BombRender->Off(); }
	if (BlinkTime > 1.95f) { BombRender->On(); }
}

void Bomb::Render(float _DeltaTime)
{
	BombCol->DebugRender();
}