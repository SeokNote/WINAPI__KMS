
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCore.h>

#include "Issac.h"
#include "ContentsEnums.h"
#include "Loki.h"
#include "BloodTear.h"

Loki* Loki::MainBoss;

Loki::Loki()
{

}

Loki::~Loki()
{
}

bool LokiImage = true;
void Loki::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");


	GameEngineImage* LokiImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Loki.BMP"));
	LokiImage->Cut(6, 3);

}


void Loki::Start()
{
	MainBoss=this;
	if (true == LokiImage)
	{
		ImageLoad();
		LokiImage = false;
	}
	LokiRender = CreateRender("Loki.BMP", IssacRenderOrder::Boss);
	LokiRender->SetScale({ 150, 150 });

	LokiRender->CreateAnimation({ .AnimationName = "Loki_Idle",  .ImageName = "Loki.bmp", .Start = 0, .End = 0, .InterTime = 0.1f });
	LokiRender->CreateAnimation({ .AnimationName = "Loki_Shoot2",  .ImageName = "Loki.bmp", .Start = 10, .End = 11, .InterTime = 0.3f });
	LokiRender->CreateAnimation({ .AnimationName = "Loki_Shoot",  .ImageName = "Loki.bmp", .Start = 1, .End = 2, .InterTime = 0.3f , .Loop = false });
	LokiRender->CreateAnimation({ .AnimationName = "Loki_Dead",  .ImageName = "Loki.bmp", .Start = 10, .End = 10, .InterTime = 0.03f , .Loop = false });

	LokiRender->ChangeAnimation("Loki_Idle");



	{

		LokiCol = CreateCollision(IssacCollisionOrder::Boss);
		LokiCol->SetScale({ 120, 100 });
		LokiCol->On();
		LokiCol->SetDebugRenderType(CollisionType::CT_Rect);

	}

}


void Loki::Update(float _DeltaTime)
{
	if (true == LokiDeathcheck) //hp가 떨어진게 확인되면
	{

		LokiRender->ChangeAnimation("Loki_Dead");
		if (true == LokiRender->IsAnimationEnd())
		{
			Death();
			GameEngineCore::GetInst()->ChangeLevel("EndLevel");

		}

	}
	LokiAttTime2 += _DeltaTime;

	LokiAttTime += _DeltaTime;

	if (LokiAttTime > 5.0f)
	{
		LokiAttTime = 0.0f;
		if (false == LokiDeathcheck)
		{
			LokiRender->ChangeAnimation("Loki_Shoot");
			float4 LokiAtt1 = float4::Left;
			float4 LokiAtt2 = float4::Right;
			float4 LokiAtt3 = float4::Up;
			float4 LokiAtt4 = float4::Down;
			BloodTear* LokiAttL = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttR = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttU = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttD = GetLevel()->CreateActor<BloodTear>();

			LokiAttL->SetBloodMoveDir(LokiAtt1);
			LokiAttR->SetBloodMoveDir(LokiAtt2);
			LokiAttU->SetBloodMoveDir(LokiAtt3);
			LokiAttD->SetBloodMoveDir(LokiAtt4);

			LokiAttL->SetPos(GetPos());
			LokiAttR->SetPos(GetPos());
			LokiAttU->SetPos(GetPos());
			LokiAttD->SetPos(GetPos());
			
		}
	}
	if (true == LokiRender->IsAnimationEnd())
	{
		LokiRender->ChangeAnimation("Loki_Idle");
		
	}

	if (LokiAttTime2 > 3.0f)
	{
		LokiAttTime2 = 0.0f;
		if (false == LokiDeathcheck)
		{
			LokiRender->ChangeAnimation("Loki_Shoot2");
			float4 LokiAtt1 = float4::Left;
			float4 LokiAtt2 = float4::Right;
			float4 LokiAtt3 = float4::Up;
			float4 LokiAtt4 = float4::Down;
			float4 LokiAtt5 = float4::LeftU;
			float4 LokiAtt6 = float4::RightU;
			float4 LokiAtt7 = float4::LeftD;
			float4 LokiAtt8 = float4::RightD;

			BloodTear* LokiAttL1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttR1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttU1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttD1 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttL2 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttR2 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttU2 = GetLevel()->CreateActor<BloodTear>();
			BloodTear* LokiAttD2 = GetLevel()->CreateActor<BloodTear>();

			LokiAttL1->SetBloodMoveDir(LokiAtt1);
			LokiAttR1->SetBloodMoveDir(LokiAtt2);
			LokiAttU1->SetBloodMoveDir(LokiAtt3);
			LokiAttD1->SetBloodMoveDir(LokiAtt4);
			LokiAttL2->SetBloodMoveDir(LokiAtt5);
			LokiAttR2->SetBloodMoveDir(LokiAtt6);
			LokiAttU2->SetBloodMoveDir(LokiAtt7);
			LokiAttD2->SetBloodMoveDir(LokiAtt8);

			LokiAttL1->SetPos(GetPos());
			LokiAttR1->SetPos(GetPos());
			LokiAttU1->SetPos(GetPos());
			LokiAttD1->SetPos(GetPos());
			LokiAttL2->SetPos(GetPos());
			LokiAttR2->SetPos(GetPos());
			LokiAttU2->SetPos(GetPos());
			LokiAttD2->SetPos(GetPos());

		}
	}
	if (true == LokiRender->IsAnimationEnd())
	{
		LokiRender->ChangeAnimation("Loki_Idle");

	}
	Movecalculation(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

void Loki::Movecalculation(float _DeltaTime)
{
	LokiSpeed = 20.0f;

	float4 M_Move = Issac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == LokiDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * LokiSpeed * _DeltaTime);
}


void Loki::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f)
	{
		NowTime = 0.0f;
		RESET = 1;

	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IssacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == LokiCol->Collision(Check, FCollisions))
	{
		//LokiRender->ChangeAnimation("Right_Monster1_Damage");
		FCollisions[0]->GetActor()->Death();
		LokiSpeed = 0.0f;

		if (1 == RESET)
		{
			LokiHp = LokiHp - Issac::MainPlayer->GetTearDamage();
			RESET = 0;
		}
		if (0 >= LokiHp)
		{
			LokiDeathcheck = true;

		}
	}



	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == LokiCol->Collision(B_Check, FCollisions))
	{
		LokiHp = LokiHp - 5;

		if (0 >= LokiHp)
		{
			LokiDeathcheck = true;


		}
	}
}

void Loki::Render(float _DeltaTime)
{
//	LokiCol->DebugRender();
}