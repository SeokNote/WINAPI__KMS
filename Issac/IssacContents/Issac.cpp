#include "Issac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

Issac* Issac::MainPlayer;

Issac::Issac()
{
}

Issac::~Issac()
{
}

void Issac::Start()
{
	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');

	}

	{
		IssacBodyRender = CreateRender(IssacRenderOrder::Player);
		IssacBodyRender->SetScale({ 55, 55 });
		IssacBodyRender->SetPosition({ 0,29 });
		//Idle
		IssacBodyRender->CreateAnimation({ .AnimationName = "Down_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Left_BIdle",  .ImageName = "Left_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Up_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Right_BIdle",  .ImageName = "Right_Issac.bmp",.Start = 8, .End = 8 });
		//Move
		IssacBodyRender->CreateAnimation({ .AnimationName = "Right_BMove",  .ImageName = "Right_Issac.bmp",.Start = 16, .End = 22, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Left_BMove", .ImageName = "Left_Issac.bmp", .Start = 16, .End = 22, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Down_BMove", .ImageName = "Left_Issac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });
		IssacBodyRender->CreateAnimation({ .AnimationName = "Up_BMove", .ImageName = "Left_Issac.bmp", .Start = 6, .End = 13, .InterTime = 0.1f });



		IssacHeadRender = CreateRender(IssacRenderOrder::Player);
		IssacHeadRender->SetScale({ 70, 70 });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Down_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });//기본상태
		IssacHeadRender->CreateAnimation({ .AnimationName = "Up_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Left_HIdle",  .ImageName = "Left_Issac.bmp",.Start = 0, .End = 0, });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Right_HIdle",  .ImageName = "Right_Issac.bmp",.Start = 0, .End = 0, });

		IssacHeadRender->CreateAnimation({ .AnimationName = "Right_HMove",  .ImageName = "Right_Issac.bmp",.Start = 2, .End = 2});
		IssacHeadRender->CreateAnimation({ .AnimationName = "Left_HMove", .ImageName = "Left_Issac.bmp", .Start = 2, .End = 2 });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Up_HMove", .ImageName = "Left_Issac.bmp", .Start = 4, .End = 5,.InterTime = 0.2f });
		IssacHeadRender->CreateAnimation({ .AnimationName = "Down_HMove", .ImageName = "Left_Issac.bmp", .Start = 0, .End = 0,.InterTime = 0.2f });

	}
	ChangeState(IssacState::IDLE);

}


 

void Issac::Update(float _DeltaTime)
{
	if (false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove") &&
		false == GameEngineInput::IsPress("DownMove") &&
		false == GameEngineInput::IsPress("UpMove"))
	{
		MoveDir = float4::Zero;
	}

	DirCheck();
	UpdateState(_DeltaTime);
	Movecalculation(_DeltaTime);
	SetMove(MoveDir * _DeltaTime);

}
void Issac::Movecalculation(float _DeltaTime)
{
	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("ColMap.BMP");
	if (nullptr == ColImage)
	{
		MsgAssert("충돌용 맵 이미지가 없습니다.");
	}
	bool Check = true;
	float4 NextPos = GetPos() + MoveDir * _DeltaTime;

	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
	{
		Check = false;
	}
	if (false == Check)
	{
		MoveDir = float4::Zero;
	}

}
void Issac::DirCheck()
{
	/*std::string PrevDirString = DirString;
	IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
	IssacBodyRender->ChangeAnimation(DirString + _AnimationName.data());*/


	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}

	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
	}

	/*if (PrevDirString != DirString)
	{
		IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
		IssacBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	}*/

}

void Issac::Render(float _DeltaTime)
{

}