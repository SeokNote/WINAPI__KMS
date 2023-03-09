#include "EndLevel.h"
#include <GameEnginePlatform/GameEngineImage.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "IntroBack.h"
#include "MouseObject.h"
#include "ContentsValue.h"
#include "EndBack.h"
EndLevel::EndLevel()
{
}

EndLevel::~EndLevel()
{
}


void EndLevel::Loading()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Title");

	// 이미지 로드
	{
		GameEngineImage* EndImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Ending1.BMP"));
		EndImage->Cut(12, 1);

		GameEngineImage* EndBackImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("EndingBack.BMP"));


	}


	CreateActor<EndBack>();
}


void EndLevel::Update(float _DeltaTime)
{



}
void EndLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{

}