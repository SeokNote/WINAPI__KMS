#include "BoomCount.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

#include "Issac.h"

BoomCount* BoomCount::BombNumberPtr = nullptr;

BoomCount::BoomCount()
{
}

BoomCount::~BoomCount()
{
}

void BoomCount::Start()
{
	BombRender = CreateRender("ItemsUI.Bmp", IssacRenderOrder::UI);
	BombRender->CreateAnimation({ .AnimationName = "BombNumber",  .ImageName = "ItemsUI.bmp", .Start = 3, .End = 3 });
	BombRender->SetPosition({ 50, 150 });
	BombRender->SetScale({ 50, 50 });
	BombRender->EffectCameraOff();
	BombRender->ChangeAnimation("BombNumber");

	N_BombNumber.SetOwner(this);
	N_BombNumber.SetImage("Number.Bmp", { 30, 30 }, 5, RGB(255, 0, 255), "ItemsUI.bmp");
	N_BombNumber.SetValue(BombNumbers);
	N_BombNumber.SetAlign(Align::Right);
	N_BombNumber.SetNumOfDigits(1);
	N_BombNumber.SetRenderPos({ 90, 150 });

}
void BoomCount::Update(float _DeltaTime)
{
	GetBombNumberSet();
	NumberSet();
}

void BoomCount::GetBombNumberSet()
{
	BombNumbers = Issac::MainPlayer->GetBombCount();
}

void BoomCount::NumberSet()
{
	N_BombNumber.SetValue(BombNumbers);
}



