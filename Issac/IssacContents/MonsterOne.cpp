#include "Issac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"
#include "MonsterOne.h"

MonsterOne::MonsterOne()
{
}

MonsterOne::~MonsterOne()
{
}

void MonsterOne::Start()
{


	{
		MonsterOneRender = CreateRender(IssacRenderOrder::Monster);
		MonsterOneRender->SetScale({ 55, 55 });
		//Idle
		MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Left_Monster1.bmp",.Start = 12, .End = 15, .InterTime = 0.1f });
		MonsterOneRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Right_Monster1.bmp",.Start = 12, .End = 15, .InterTime = 0.1f });
		//Move
		MonsterOneRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Right_Monster1.bmp",.Start = 0, .End = 4, .InterTime = 0.1f });
		MonsterOneRender->CreateAnimation({ .AnimationName = "Left_Move", .ImageName = "Left_Monster1.bmp", .Start = 0, .End = 4, .InterTime = 0.1f });

	}
	ChangeState(MonsterState::IDLE);

}




void MonsterOne::Update(float _DeltaTime)
{
	float4 Dir = Issac::MainPlayer->GetPos() - GetPos();
	Dir.Normalize();


	DirCheck();
	SetMove(MoveDir * _DeltaTime);

}
//void Issac::Movecalculation(float _DeltaTime)
//{
//	GameEngineImage* ColImage = GameEngineResources::GetInst().ImageFind("ColMap.BMP");
//	if (nullptr == ColImage)
//	{
//		MsgAssert("충돌용 맵 이미지가 없습니다.");
//	}
//	bool Check = true;
//	float4 NextPos = GetPos() + MoveDir * _DeltaTime;
//
//	if (RGB(0, 0, 0) == ColImage->GetPixelColor(NextPos, RGB(0, 0, 0)))
//	{
//		Check = false;
//	}
//	if (false == Check)
//	{
//		MoveDir = float4::Zero;
//	}
//
//}
void MonsterOne::DirCheck()
{
	/*std::string PrevDirString = DirString;
	IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
	IssacBodyRender->ChangeAnimation(DirString + _AnimationName.data());*/


	//if (GameEngineInput::IsPress("LeftMove"))
	//{
	//	DirString = "Left_";
	//}
	//else if (GameEngineInput::IsPress("RightMove"))
	//{
	//	DirString = "Right_";
	//}
	//else if (GameEngineInput::IsPress("UpMove"))
	//{
	//	DirString = "Up_";
	//}

	//else if (GameEngineInput::IsPress("DownMove"))
	//{
	//	DirString = "Down_";
	//}

	/*if (PrevDirString != DirString)
	{
		IssacHeadRender->ChangeAnimation(DirString + _AnimationName.data());
		IssacBodyRender->ChangeAnimation(DirString + _AnimationName.data());
	}*/

}

void MonsterOne::Render(float _DeltaTime)
{

}