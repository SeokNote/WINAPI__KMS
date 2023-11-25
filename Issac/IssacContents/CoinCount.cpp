#include "CoinCount.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

#include "Isaac.h"

CoinCount* CoinCount::CoinNumberPtr = nullptr;

CoinCount::CoinCount()
{
}

CoinCount::~CoinCount()
{
}

void CoinCount::Start()
{
	CoinRender = CreateRender("ItemsUI.Bmp", IsaacRenderOrder::UI);
	CoinRender->CreateAnimation({ .AnimationName = "CoinNumber",  .ImageName = "ItemsUI.bmp", .Start = 0, .End = 0 });
	CoinRender->SetPosition({ 50, 200 });
	CoinRender->SetScale({ 50, 50 });
	CoinRender->EffectCameraOff();
	CoinRender->ChangeAnimation("CoinNumber");

	N_CoinRender.SetOwner(this);
	N_CoinRender.SetImage("Number.Bmp", { 30, 30 }, 5, RGB(255, 0, 255), "ItemsUI.bmp");
	N_CoinRender.SetValue(CoinNumbers);
	N_CoinRender.SetAlign(Align::Right);
	N_CoinRender.SetNumOfDigits(1);
	N_CoinRender.SetRenderPos({ 90, 200 });

}
void CoinCount::Update(float _DeltaTime)
{
	GetCoinNumberSet();
	NumberSet();
}

void CoinCount::GetCoinNumberSet()
{
	CoinNumbers = Isaac::MainPlayer->GetCoinCount();
}

void CoinCount::NumberSet()
{
	N_CoinRender.SetValue(CoinNumbers);
}



