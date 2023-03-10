#include "HP.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

#include "Issac.h"

HP::HP()
{
}

HP::~HP()
{
}

void HP::Start()
{
	HpRender6 = CreateRender("PlayerHP6.Bmp", IssacRenderOrder::UI);
	HpRender5 = CreateRender("PlayerHP5.Bmp", IssacRenderOrder::UI);
	HpRender4 = CreateRender("PlayerHP4.Bmp", IssacRenderOrder::UI);
	HpRender3 = CreateRender("PlayerHP3.Bmp", IssacRenderOrder::UI);
	HpRender2 = CreateRender("PlayerHP2.Bmp", IssacRenderOrder::UI);
	HpRender1 = CreateRender("PlayerHP1.Bmp", IssacRenderOrder::UI);
	HpRender0 = CreateRender("PlayerHP0.Bmp", IssacRenderOrder::UI);


}
void HP::Update(float _DeltaTime)
{
	SetIsaacHP();

	HpSet(IsaacHP);
}

void HP::SetIsaacHP()
{
	IsaacHP = Issac::MainPlayer->GetPlayerHP();
}

void HP::HpSet(int _PlayerHP)
{
	if (6 == _PlayerHP)
	{
		HpRender6->SetPosition({ 100, 50 });
		HpRender6->SetScale({ 135,42 });
		HpRender6->EffectCameraOff();

	}
	else if (5 == _PlayerHP)
	{
		HpRender5->SetPosition({ 100, 50 });
		HpRender5->SetScale({ 135,42 });
		HpRender5->EffectCameraOff();
	}
	else if (4 == _PlayerHP)
	{
		HpRender4->SetPosition({ 100, 50 });
		HpRender4->SetScale({ 135,42 });
		HpRender4->EffectCameraOff();
	}
	else if (3 == _PlayerHP)
	{

		HpRender3->SetPosition({ 100, 50 });
		HpRender3->SetScale({ 135,42 });
		HpRender3->EffectCameraOff();

	}
	else if (2 == _PlayerHP)
	{
		HpRender2->SetPosition({ 100, 50 });
		HpRender2->SetScale({ 135,42 });
		HpRender2->EffectCameraOff();
	}
	else if (1 == _PlayerHP)
	{

		HpRender1->SetPosition({ 100, 50 });
		HpRender1->SetScale({ 135,42 });
		HpRender1->EffectCameraOff();
	}
	else if (0 <= _PlayerHP)
	{
		HpRender0->SetPosition({ 100, 50 });
		HpRender0->SetScale({ 135,42 });
		HpRender0->EffectCameraOff();


	}
}



