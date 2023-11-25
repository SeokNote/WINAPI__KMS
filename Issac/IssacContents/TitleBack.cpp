#include "TitleBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

TitleBack::TitleBack()
{
}

TitleBack::~TitleBack()
{
}


void TitleBack::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();


	TitleRender = CreateRender(IsaacRenderOrder::title);
	TitleRender->SetPosition(GameEngineWindow::GetScreenSize().half());
	TitleRender->SetScale(GameEngineWindow::GetScreenSize());
	TitleRender->CreateAnimation({ .AnimationName = "Loop",  .ImageName = "start.bmp", .Start = 0, .End = 1, .InterTime = 0.3f });
	TitleRender->ChangeAnimation("Loop");
}