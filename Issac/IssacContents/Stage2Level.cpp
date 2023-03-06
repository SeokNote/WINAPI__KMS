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


	
}
void Stage2Level::Loading()
{

	ImageLoad();

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
