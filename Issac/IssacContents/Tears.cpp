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
#include "issac.h"



Tears::Tears()
{

}

Tears::~Tears()
{

}

void Tears::Start()
{
	//// ���� ����
	//GameEngineDirectory Dir;
	//Dir.MoveParentToDirectory("ContentsResources");
	//Dir.Move("ContentsResources");
	//Dir.Move("Image");
	//Dir.Move("Play");

	//// �̹��� �ε�
	//{
	//	GameEngineImage* T_Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear.BMP"));
	//	T_Image->Cut(8, 4);
	//	GameEngineImage* T_ImagePop = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Tear_Pop.BMP"));
	//	T_ImagePop->Cut(4, 4);
	//}
	{
		TearsRender = CreateRender(IssacRenderOrder::Player);
		TearsRender->SetScale({ 64, 64 });
		TearsRender->SetPosition({ 0,0 });
		TearsRender->CreateAnimation({ .AnimationName = "Tears", .ImageName = "Tear.BMP", .Start = 6, .End = 6, .InterTime = 0.1f });
		TearsRender->CreateAnimation({ .AnimationName = "Pop", .ImageName = "Tear_Pop.BMP", .Start = 0, .End = 15, .InterTime = 0.03f , .Loop = false });
	}
	TearsRender->ChangeAnimation("Tears");

	// Collision ����
	{
		Collision = CreateCollision(IssacCollisionOrder::PlayerAttack);
		Collision->SetScale({ 20, 20 });
		Collision->SetPosition({ 0, -20 });
		Collision->SetDebugRenderType(CollisionType::CT_Rect);
	}

}

void Tears::Update(float _DeltaTime)
{
	GravityTime += _DeltaTime;
	if (GravityTime > 0.8f)
	{
		MoveDir = float4::Left * LTearfallValue + float4::Down * (0.4f);
	}
	if (GravityTime > 0.9f)
	{
		TearsRender->ChangeAnimation("Pop");

		MoveDir = float4::Zero;
		if (true == TearsRender->IsAnimationEnd())
		{
			Death();
		}
	}
	MoveCalculation(_DeltaTime);
	SetMove(MoveDir * 400.0f * _DeltaTime);
}

void Tears::MoveCalculation(float _DeltaTime)
{

	float4 NextPos = GetPos() - GetLevel()->GetCameraPos() + MoveDir * _DeltaTime;
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("ColMap.BMP");

	if (nullptr == ColImage)
	{
		MsgAssert("�浹�� �� �̹����� �����ϴ�.");
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
