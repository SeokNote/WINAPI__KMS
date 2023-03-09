
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Issac.h"
#include "ContentsEnums.h"
#include "MonsterTwo.h"


MonsterTwo::MonsterTwo()
{

}

MonsterTwo::~MonsterTwo()
{

}

void MonsterTwo::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");

	GameEngineImage* MonsterTwo = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Monster02.BMP"));
	MonsterTwo->Cut(4, 2);


}
bool LoadMonster = true;

void MonsterTwo::Start()
{
	if (true == LoadMonster) {
		ImageLoad();
		LoadMonster = false;
	}
	MonsterTwoRender = CreateRender(IssacRenderOrder::Monster); //랜더 생성 후 크기 설정 후 애니메이션 만들기
	MonsterTwoRender->SetScale({ 80,80 }); 


	MonsterTwoRender->CreateAnimation({ .AnimationName = "MonsterOneIdle",  .ImageName = "Monster02.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	MonsterTwoRender->CreateAnimation({ .AnimationName = "MonsterOneHit",  .ImageName = "Monster02.bmp", .Start = 5, .End = 6, .InterTime = 0.1f });
	MonsterTwoRender->CreateAnimation({ .AnimationName = "MonsterOneDead",  .ImageName = "Monster02_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.1f, .Loop = false });
	MonsterTwoRender->ChangeAnimation("MonsterOneIdle");


	// 충돌생성
	MonsterTwoCol = CreateCollision(IssacCollisionOrder::Monster);
	MonsterTwoCol->SetScale({ 10,10 });
	MonsterTwoCol->On();
	MonsterTwoCol->SetDebugRenderType(CollisionType::CT_Rect);
}


void MonsterTwo::Update(float _DeltaTime)
{

	if (MonsterTwoHp <= 0) {
		MoveA = float4::Zero;
		MonsterTwoRender->ChangeAnimation("MonsterOneDead");
		if (MonsterTwoRender->IsAnimationEnd()) 
		{
			Death();
		}
	}


	Movecalculation(_DeltaTime);
	SetMove(MoveA * 60.0f * _DeltaTime);
	CollisionCheck(_DeltaTime);
}

void MonsterTwo::Movecalculation(float _DeltaTime)
{
	MoveA = Issac::MainPlayer->GetPos() - GetPos();

	MoveA.Normalize();


}

bool Invincible = false;
void MonsterTwo::CollisionCheck(float _DeltaTime)
{
	CollTime += _DeltaTime;
	if (CollTime >= 0.1f)
	{
		CollTime = 0.0f;
		MonsterTwoCol->On();
		Invincible = true;
	}

	std::vector<GameEngineCollision*> Collisions;
	CollisionCheckParameter CheckAttack = { .TargetGroup = static_cast<int>(IssacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	CollisionCheckParameter CheckBomb = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == MonsterTwoCol->Collision(CheckAttack, Collisions)) 
	{
		MonsterTwoRender->ChangeAnimation("MonsterOneHit");
		Collisions[0]->GetActor()->Death(); 
		SetMove(float4::Right * 20);

		if (true == Invincible)
		{
			MonsterTwoHp -= Issac::MainPlayer->GetTearDamage();
			MonsterTwoCol->Off();
		}

	}

	if (true == MonsterTwoCol->Collision(CheckBomb, Collisions))
	{
		MonsterTwoRender->ChangeAnimation("MonsterOneDead");
		Collisions[0]->GetActor()->Death();
	}
}

void MonsterTwo::Render(float _DeltaTime)
{

}