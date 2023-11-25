
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Isaac.h"
#include "ContentsEnums.h"
#include "Pooter.h"
#include "BloodTear.h"


Pooter::Pooter()
{

}

Pooter::~Pooter()
{
}

bool PooterLoad = true;
void Pooter::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");


	GameEngineImage* Pooter = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Monster1.BMP"));
	Pooter->Cut(4, 4);
	GameEngineImage* Pooter1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Monster1.BMP"));
	Pooter1->Cut(4, 4);

}


void Pooter::Start()
{
	if (true == PooterLoad)
	{
		ImageLoad();
		PooterLoad = false;
	}
	PooterRender = CreateRender("Right_Monster1.BMP",IsaacRenderOrder::Monster);
	PooterRender->SetScale({ 80, 80 });

	PooterRender->CreateAnimation({ .AnimationName = "Right_Monster1_Idle",  .ImageName = "Right_Monster1.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	PooterRender->CreateAnimation({ .AnimationName = "Right_Monster1_Damage",  .ImageName = "Right_Monster1.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	PooterRender->CreateAnimation({ .AnimationName = "Right_Monster1_Shoot",  .ImageName = "Right_Monster1.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
														  
	PooterRender->CreateAnimation({ .AnimationName = "Left_Monster1_Idle",  .ImageName = "Left_Monster1.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	PooterRender->CreateAnimation({ .AnimationName = "Left_Monster1_Damage",  .ImageName = "Left_Monster1.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	PooterRender->CreateAnimation({ .AnimationName = "Left_Monster1_Shoot",  .ImageName = "Left_Monster1.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
	PooterRender->CreateAnimation({ .AnimationName = "Left_Monster1_Dead",  .ImageName = "Monster02_Dead.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	PooterRender->ChangeAnimation("Right_Monster1_Idle");



	{

		PooterCol = CreateCollision(IsaacCollisionOrder::Monster);
		PooterCol->SetScale({ 35, 35 });
		PooterCol->On();
		PooterCol->SetDebugRenderType(CollisionType::CT_Rect);
		
		PooterSet = CreateCollision(IsaacCollisionOrder::MonsterSet);
		PooterSet->SetScale({ 800, 800 });
		PooterSet->SetPosition({ 400,0 });
		PooterSet->On();
		PooterSet->SetDebugRenderType(CollisionType::CT_Rect);


	}

}


void Pooter::Update(float _DeltaTime)
{
	if (true == PooterDeathcheck) //hp가 떨어진게 확인되면
	{
		
		PooterRender->ChangeAnimation("Left_Monster1_Dead");
		if (true == PooterRender->IsAnimationEnd())
		{
			Death();
		}
		
	}
	PooterAttTime += _DeltaTime;
	if (PooterAttTime > 3.0f)
	{
		PooterAttTime = 0.0f;
		if (false == PooterDeathcheck)
		{

			if (true == PooterSet->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				PooterRender->ChangeAnimation("Right_Monster1_Shoot");
				float4 PlayerPos_P = Isaac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt = GetLevel()->CreateActor<BloodTear>();
				PooterAtt->SetBloodMoveDir(PlayerPos_P);
				PooterAtt->SetPos(GetPos());
			}
			else
			{
				PooterRender->ChangeAnimation("Left_Monster1_Shoot");
				float4 PlayerPos_P1 = Isaac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt1 = GetLevel()->CreateActor<BloodTear>();
				PooterAtt1->SetBloodMoveDir(PlayerPos_P1);
				PooterAtt1->SetPos(GetPos());
			}
		}
	}
	if (true == PooterRender->IsAnimationEnd())
	{
		if (true == PooterSet->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			PooterRender->ChangeAnimation("Right_Monster1_Idle"); //다시 idle로바꾸고
		}
		else
		{
			PooterRender->ChangeAnimation("Left_Monster1_Idle");
		}
	}

	MonsterBase::Movecalculation(_DeltaTime, PooterDeathcheck);
	CollisionCheck(_DeltaTime);
}



void Pooter::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f) 
	{
		NowTime = 0.0f;
		PooterSet->On();
		RESET = 1;

	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == PooterCol->Collision(Check, FCollisions)) 
	{
		PooterRender->ChangeAnimation("Right_Monster1_Damage");
		FCollisions[0]->GetActor()->Death();
		SetMove(float4::Left * 20); 

		if (1 == RESET)
		{
			PooterHp = PooterHp - Isaac::MainPlayer->GetTearDamage();
			RESET = 0;
			PooterSet->Off(); 
		}
		if (0 >= PooterHp)
		{
			
			PooterDeathcheck = true;
			

		}
	}
	


	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IsaacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == PooterSet->Collision(B_Check, FCollisions))
	{
		PooterHp = PooterHp - 5; 

		if (0 >= PooterHp)
		{
			PooterDeathcheck = true;
			

		}
	}

}

void Pooter::Render(float _DeltaTime)
{
}