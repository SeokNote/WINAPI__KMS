#include "IntroBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

IntroBack::IntroBack()
{
}

IntroBack::~IntroBack()
{
}


void IntroBack::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();


	GameEngineRender* Render = CreateRender("main.bmp", IssacRenderOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
}