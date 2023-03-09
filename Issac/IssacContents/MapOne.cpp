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


	GameEngineRender* Render = CreateRender("BaseMap.bmp", IssacRenderOrder::BackGround);
	Render->SetPosition(Render->GetImage()->GetImageScale().half());
	Render->SetScaleToImage();

}