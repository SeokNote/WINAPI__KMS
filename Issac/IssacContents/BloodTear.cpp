#include "BloodTear.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include<GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineResources.h>

#include "ContentsEnums.h"
#include "Isaac.h"



BloodTear::BloodTear()
{

}

BloodTear::~BloodTear()
{

}

bool BloodTearLoad = true;
void BloodTear::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	GameEngineImage* BloodTear = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("BloodTear_Pop.BMP"));
	BloodTear->Cut(4, 4);
}

void BloodTear::Start()
{
	if (true == BloodTearLoad)
	{
		ImageLoad();
		BloodTearLoad = false;
	}
	{
		BloodTearRender = CreateRender(IsaacRenderOrder::Player);
		BloodTearRender->SetScale({ 90, 90 });
		BloodTearRender->CreateAnimation({ .AnimationName = "Base", .ImageName = "BloodTear_Pop.BMP", .Start = 0, .End = 0, .InterTime = 0.1f });
		BloodTearRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "BloodTear_Pop.BMP", .Start = 1, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	BloodTearRender->ChangeAnimation("Base");

	{
		BloodTearCol = CreateCollision(IsaacCollisionOrder::MonsterAttack);
		BloodTearCol->SetScale({ 20, 20 });
		BloodTearCol->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void BloodTear::Update(float _DeltaTime)
{
	TearTime += _DeltaTime;
	if (TearTime > 2.0f)
	{
		BloodTearRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == BloodTearRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * 300.0f * _DeltaTime);
}

void BloodTear::MoveCalculation(float _DeltaTime)
{
	float4 NextPos = GetPos() - GetLevel()->GetCameraPos() + MoveDir * _DeltaTime;

	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BaseColMap.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		BloodTearRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == BloodTearRender->IsAnimationEnd())
		{
			Death();
		}
	}
}

void BloodTear::Render(float _DeltaTime)
{
	//Collision->DebugRender();
}
