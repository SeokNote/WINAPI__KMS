
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "ContentsEnums.h"
#include "Fly.h"


Fly::Fly()
{

}

Fly::~Fly()
{

}

void Fly::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");

	GameEngineImage* Fly = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monster02.BMP"));
	Fly->Cut(4, 2);


}
bool LoadMonster = true;

void Fly::Start()
{
	if (true == LoadMonster) {
		ImageLoad();
		LoadMonster = false;
	}
	FlyRender = CreateRender(IsaacRenderOrder::Monster); //랜더 생성 후 크기 설정 후 애니메이션 만들기
	FlyRender->SetScale({ 80,80 }); 


	FlyRender->CreateAnimation({ .AnimationName = "MonsterOneIdle",  .ImageName = "Monster02.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	FlyRender->CreateAnimation({ .AnimationName = "MonsterOneHit",  .ImageName = "Monster02.bmp", .Start = 5, .End = 6, .InterTime = 0.1f });
	FlyRender->CreateAnimation({ .AnimationName = "MonsterOneDead",  .ImageName = "Monster02_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.1f, .Loop = false });
	FlyRender->ChangeAnimation("MonsterOneIdle");


	// 충돌생성
	FlyCol = CreateCollision(IsaacCollisionOrder::Monster);
	FlyCol->SetScale({ 10,10 });
	FlyCol->On();
	FlyCol->SetDebugRenderType(CollisionType::CT_Rect);
}


void Fly::Update(float _DeltaTime)
{

	if (FlyHp <= 0) {
		MoveA = float4::Zero;
		FlyRender->ChangeAnimation("MonsterOneDead");
		if (FlyRender->IsAnimationEnd()) 
		{
			Death();
		}
	}


	Movecalculation(_DeltaTime);
	SetMove(MoveA * 60.0f * _DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Fly::Movecalculation(float _DeltaTime)
{
	MoveA = Isaac::MainPlayer->GetPos() - GetPos();

	MoveA.Normalize();


}

bool Invincible = false;
void Fly::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 0.1f)
	{
		CollTime = 0.0f;
		FlyCol->On();
		Invincible = true;
	}

	std::vector<GameEngineCollision*> Collisions;
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckBomb = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == FlyCol->Collision(CheckAttack, Collisions)) 
	{
		FlyRender->ChangeAnimation("MonsterOneHit");
		Collisions[0]->GetActor()->Death(); 
		SetMove(float4::Right * 20);

		if (true == Invincible)
		{
			FlyHp -= Isaac::MainPlayer->GetTearDamage();
			FlyCol->Off();
		}

	}

	if (true == FlyCol->Collision(CheckBomb, Collisions))
	{
		FlyRender->ChangeAnimation("MonsterOneDead");
		Collisions[0]->GetActor()->Death();
	}
}

void Fly::Render(float _DeltaTime)
{

}