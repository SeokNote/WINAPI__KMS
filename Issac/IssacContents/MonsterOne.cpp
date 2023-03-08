
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>


#include "Issac.h"
#include "ContentsEnums.h"
#include "MonsterOne.h"
#include "BloodTear.h"


MonsterOne::MonsterOne()
{

}

MonsterOne::~MonsterOne()
{
}

bool PooterLoad = true;
void MonsterOne::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");


	GameEngineImage* MonsterOne = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Monster1.BMP"));
	MonsterOne->Cut(4, 4);
	GameEngineImage* MonsterOne1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Monster1.BMP"));
	MonsterOne1->Cut(4, 4);

}


void MonsterOne::Start()
{
	if (true == PooterLoad)
	{
		ImageLoad();
		PooterLoad = false;
	}
	MonsterOneRender = CreateRender("Right_Monster1.BMP",IssacRenderOrder::Monster);
	MonsterOneRender->SetScale({ 80, 80 });

	MonsterOneDead = CreateRender(IssacRenderOrder::Dead);
	MonsterOneDead->SetScale({ 80, 80 });

	MonsterOneRender->CreateAnimation({ .AnimationName = "Right_Monster1_Idle",  .ImageName = "Right_Monster1.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	MonsterOneRender->CreateAnimation({ .AnimationName = "Right_Monster1_Damage",  .ImageName = "Right_Monster1.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	MonsterOneRender->CreateAnimation({ .AnimationName = "Right_Monster1_Shoot",  .ImageName = "Right_Monster1.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
														  
	MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Monster1_Idle",  .ImageName = "Left_Monster1.bmp", .Start = 0, .End = 1, .InterTime = 0.1f });
	MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Monster1_Damage",  .ImageName = "Left_Monster1.bmp", .Start = 14, .End = 15, .InterTime = 0.1f });
	MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Monster1_Shoot",  .ImageName = "Left_Monster1.bmp", .Start = 2, .End = 11, .InterTime = 0.03f , .Loop = false });
	MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Monster1_Dead",  .ImageName = "Left_Monster1.bmp", .Start = 0, .End = 11, .InterTime = 0.03f, .Loop = false });
	MonsterOneRender->ChangeAnimation("Right_Monster1_Idle");



	{

		MonsterOneCol = CreateCollision(IssacCollisionOrder::Monster);
		MonsterOneCol->SetScale({ 35, 35 });
		MonsterOneCol->On();
		MonsterOneCol->SetDebugRenderType(CollisionType::CT_Rect);
		
		MonsterOneSet = CreateCollision(IssacCollisionOrder::MonsterSet);
		MonsterOneSet->SetScale({ 800, 800 });
		MonsterOneSet->SetPosition({ 400,0 });
		MonsterOneSet->On();
		MonsterOneSet->SetDebugRenderType(CollisionType::CT_Rect);


	}

}


void MonsterOne::Update(float _DeltaTime)
{
	if (true == PooterDeathcheck) //hp가 떨어진게 확인되면
	{
		
		MonsterOneRender->ChangeAnimation("Left_Monster1_Dead");
		if (true == MonsterOneRender->IsAnimationEnd())
		{
			MonsterOneDead->On();
			MonsterOneRender->Death();
		}
		Death();
	}
	MonsterOneAttTime += _DeltaTime;
	if (MonsterOneAttTime > 3.0f)
	{
		MonsterOneAttTime = 0.0f;
		if (false == PooterDeathcheck)
		{

			if (true == MonsterOneSet->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
			{
				MonsterOneRender->ChangeAnimation("Right_Monster1_Shoot");
				float4 PlayerPos_P = Issac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt = GetLevel()->CreateActor<BloodTear>();
				PooterAtt->SetBloodMoveDir(PlayerPos_P);
				PooterAtt->SetPos(GetPos());
			}
			else
			{
				MonsterOneRender->ChangeAnimation("Left_Monster1_Shoot");
				float4 PlayerPos_P1 = Issac::MainPlayer->GetPos() - GetPos();
				BloodTear* PooterAtt1 = GetLevel()->CreateActor<BloodTear>();
				PooterAtt1->SetBloodMoveDir(PlayerPos_P1);
				PooterAtt1->SetPos(GetPos());
			}
		}
	}
	if (true == MonsterOneRender->IsAnimationEnd())
	{
		if (true == MonsterOneSet->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::Player), .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
		{
			MonsterOneRender->ChangeAnimation("Right_Monster1_Idle"); //다시 idle로바꾸고
		}
		else
		{
			MonsterOneRender->ChangeAnimation("Left_Monster1_Idle");
		}
	}

//	Movecalculation(_DeltaTime);
//	CollisionCheck(_DeltaTime);
}

void MonsterOne::Movecalculation(float _DeltaTime)
{
	float4 M_Move = Issac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == PooterDeathcheck)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 15.0f * _DeltaTime); //안따라다니게할때는 M_Move를 다르게설정하면될듯 >>움직이는 제한pos를 BackGround_CS로 해야함
}


void MonsterOne::CollisionCheck(float _DeltaTime)
{
	NowTime += _DeltaTime;

	if (NowTime >= 0.5f) //다음상호작용이 되려면 이만큼의 시간이 흘러야한다(몬스터가 죽는애니메이션시간보다는 길어야함)
	{
		NowTime = 0.0f;
		MonsterOneSet->On();  //시간이지나면 다시collision을킨다
		RESET = 1;

	}

	std::vector<GameEngineCollision*> FCollisions;
	CollisionCheckParameter Check = { .TargetGroup = static_cast<int>(IssacCollisionOrder::PlayerAttack), .TargetColType = CT_Rect, .ThisColType = CT_Rect };

	if (true == MonsterOneSet->Collision(Check, FCollisions)) //PlayerAtt에 닿았을때
	{
		MonsterOneRender->ChangeAnimation("Right_Monster1_Damage");
		FCollisions[0]->GetActor()->Death(); //닿은 ATT는 지워버리고
		SetMove(float4::Left * 20); //맞으면 밀려남(매끄럽게안밀려남) 방향에따른 설정도해야할듯

		if (1 == RESET)
		{
			PooterHp = PooterHp - Issac::MainPlayer->GetTearDamage();
			RESET = 0;
			MonsterOneSet->Off(); //맞아도 일정시간동안 상호작용이안된다.
		}
		if (0 >= PooterHp)
		{
			PooterDeathcheck = true;
		}
	}
	


	CollisionCheckParameter B_Check = { .TargetGroup = static_cast<int>(IssacCollisionOrder::Bomb), .TargetColType = CT_Rect, .ThisColType = CT_Rect };
	if (true == MonsterOneSet->Collision(B_Check, FCollisions))
	{
		PooterHp = PooterHp - 5; //이것은 폭탄의 데미지여
		if (0 >= PooterHp)
		{
			MonsterOneRender->ChangeAnimation("Right_Monster1_Dead");
			PooterDeathcheck = true;
		}
	}
}

void MonsterOne::Render(float _DeltaTime)
{
	//M_fly_Pooter->DebugRender();
	//M_fly_Pooter_Set->DebugRender();
}