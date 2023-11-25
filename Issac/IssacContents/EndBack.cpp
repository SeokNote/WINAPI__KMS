#include "EndBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

EndBack::EndBack()
{
}

EndBack::~EndBack()
{
}


void EndBack::Start()
{
	EndRender = CreateRender(IsaacRenderOrder::Object);
	EndRender->SetPosition(GameEngineWindow::GetScreenSize().half());
	EndRender->SetScale({512,256});
	EndRender->CreateAnimation({ .AnimationName = "Loop",  .ImageName = "Ending1.bmp", .Start = 0, .End = 11, .InterTime = 0.3f , .Loop = false});
	EndRender->ChangeAnimation("Loop");

	GameEngineRender* Render = CreateRender("EndingBack.bmp", IsaacRenderOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());

}