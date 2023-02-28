#include "IntroLevel.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "IntroBack.h"
#include "MouseObject.h"
#include "ContentsValue.h"

IntroLevel::IntroLevel()
{
}

IntroLevel::~IntroLevel()
{
}


void IntroLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	// 이미지 로드
	{
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Main.BMP"));
	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'P');

	}


	CreateActor<IntroBack>();

	Start = float4::Zero;
	End = float4(0.0f, GameEngineWindow::GetScreenSize().half().y);

}


void IntroLevel::Update(float _DeltaTime)
{
	// if (true == GameEngineInput::IsDown("LevelChange"))
	if (true == GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::GetInst()->ChangeLevel("TestLevel");
	}




}


void IntroLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ContentsValue::CameraScale = { 2000, 3000 };
}