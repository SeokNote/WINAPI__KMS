#include "KeyCount.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

#include "Issac.h"

KeyCount* KeyCount::KeyNumberPtr = nullptr;

KeyCount::KeyCount()
{
}

KeyCount::~KeyCount()
{
}

void KeyCount::Start()
{
	KeyRender = CreateRender("ItemsUI.Bmp", IssacRenderOrder::UI);
	KeyRender->CreateAnimation({ .AnimationName = "KeyNumber",  .ImageName = "ItemsUI.bmp", .Start = 1, .End = 1 });
	KeyRender->SetPosition({ 50, 250 });
	KeyRender->SetScale({ 50, 50 });
	KeyRender->EffectCameraOff();
	KeyRender->ChangeAnimation("KeyNumber");
	
	
	N_KeyRender.SetOwner(this);
	N_KeyRender.SetImage("Number.Bmp", { 30, 30 }, 5, RGB(255, 0, 255), "ItemsUI.bmp");
	N_KeyRender.SetValue(KeyNumbers);
	N_KeyRender.SetAlign(Align::Right);
	N_KeyRender.SetNumOfDigits(1);
	N_KeyRender.SetRenderPos({ 90, 250 });

}
void KeyCount::Update(float _DeltaTime)
{
	GetKeyNumberSet();
	NumberSet();
}

void KeyCount::GetKeyNumberSet()
{
	KeyNumbers = Issac::MainPlayer->GetKeyCount();
}

void KeyCount::NumberSet()
{
	N_KeyRender.SetValue(KeyNumbers);
}



