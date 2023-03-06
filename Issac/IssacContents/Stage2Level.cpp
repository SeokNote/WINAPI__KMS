#include "Stage2Level.h"
#include "Issac.h"
#include "MonsterOne.h"
#include "Door.h"

#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/Button.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "MapOne.h"
#include "MouseObject.h"
#include "ContentsValue.h"

Stage2Level::Stage2Level()
{
}

Stage2Level::~Stage2Level()
{
}

void Stage2Level::ImageLoad() {


	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");

	// 이미지 로드
	{
		GameEngineImage* Image1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("StartOne.BMP"));
		GameEngineImage* ColImage = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("ColMap.BMP"));//맵
		GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Door_Down.BMP"));

		{
			GameEngineImage* Image = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Issac.BMP"));
			Image->Cut(8, 4);
		}
		{
			GameEngineImage* Image2 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Issac.BMP"));
			Image2->Cut(8, 4);
		}
		/*{
			GameEngineImage* MonsterImage1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Left_Monster1.BMP"));
			MonsterImage1->Cut(4, 4);
		}
		{
			GameEngineImage* MonsterImage1 = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Right_Monster1.BMP"));
			MonsterImage1->Cut(4, 4);
		}*/
	}

}
void Stage2Level::Loading()
{

	ImageLoad();

	/*Issac* NewIssac = CreateActor<Issac>();
	NewIssac->SetPos({ 500,500 });*/

	/*MonsterOne* NewMonster1 = CreateActor<MonsterOne>();
	NewMonster1->SetPos({ 200,200 });*/

	CreateActor<MapOne>();
	CreateActor<Door>();

	Start = float4::Zero;
	End = float4(0.0f, GameEngineWindow::GetScreenSize().half().y);

}


void Stage2Level::Update(float _DeltaTime)
{


}


void Stage2Level::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
	ContentsValue::CameraScale = { 2000, 3000 };
}
