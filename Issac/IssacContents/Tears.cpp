#include "Tears.h"
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



Tears::Tears()
{

}

Tears::~Tears()
{

}

void Tears::Start()
{
	//// 렌더 생성
	//GameEngineDirectory Dir;
	//Dir.MoveParentToDirectory("ContentsResources");
	//Dir.Move("ContentsResources");
	//Dir.Move("Image");
	//Dir.Move("Play");

	//// 이미지 로드
	//{
	//	GameEngineImage* T_Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.BMP"));
	//	T_Image->Cut(8, 4);
	//	GameEngineImage* T_ImagePop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.BMP"));
	//	T_ImagePop->Cut(4, 4);
	//}
	{
		TearsRender = CreateRender(IsaacRenderOrder::Player);
		TearsRender->SetScale({ 64, 64 });
		TearsRender->SetPosition({ 0,0 });
		TearsRender->CreateAnimation({ .AnimationName = "Tears", .ImageName = "Tear.BMP", .Start = 6, .End = 6, .InterTime = 0.1f });
		TearsRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "Tear_Pop.BMP", .Start = 0, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	TearsRender->ChangeAnimation("Tears");

	// Collision 생성
	{
		Collision = CreateCollision(IsaacCollisionOrder::PlayerAttack);
		Collision->SetScale({ 20, 20 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void Tears::Update(float _DeltaTime)
{
	GravityTime += _DeltaTime;
	if (GravityTime > 1.0f)
	{
		MoveDir = float4::Left * LTearfallValue + float4::Down * (0.4f);
	}
	if (GravityTime > 1.1f)
	{
		TearsRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == TearsRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * Isaac::MainPlayer->GetTearSpeed() * _DeltaTime);
}

void Tears::MoveCalculation(float _DeltaTime)
{

	float4 NextPos = GetPos() - MoveDir * _DeltaTime;
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("BaseColMap.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		TearsRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == TearsRender->IsAnimationEnd())
		{
			Death();
		}
	}
}


void Tears::Render(float _DeltaTime)
{
//	Collision->DebugRender();
}
