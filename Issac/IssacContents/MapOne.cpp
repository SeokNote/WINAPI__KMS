#include "MapOne.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

MapOne::MapOne()
{
}

MapOne::~MapOne()
{
}


void MapOne::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();


	GameEngineRender* Render = CreateRender("StartOne.bmp", IssacRenderOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());

}