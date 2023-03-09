#include "HpBar.h"
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

#include "Loki.h"

HpBar::HpBar()
{
}

HpBar::~HpBar()
{
}
void HpBar::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");
	Dir.Move("Monsters");

	GameEngineImage* LoadHpbar = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Hpbar.BMP"));
	LoadHpbar->Cut(1, 2);
	GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Hpbar2.BMP"));

}
bool HpbarLoad = true;
void HpBar::Start()
{
	if (true == HpbarLoad)
	{
		ImageLoad();
		HpbarLoad = false;
	}
	HpbarRender = CreateRender(IssacRenderOrder::Object);
	HpbarRender->CreateAnimation({ .AnimationName = "HpBar",  .ImageName = "Hpbar.bmp", .Start = 1, .End = 1 });
	HpbarRender->SetScale({ 450, 96 });
	HpbarRender->ChangeAnimation("HpBar");

	HpbarBackRender = CreateRender("Hpbar2.BMP", IssacRenderOrder::Object);
	HpbarBackRender->SetScale({ 330, 96 });
	HpbarBackRender->SetPosition({ 5,0 });

}

void HpBar::Update(float _DeltaTime)
{
	SetLokiHP();
	Renders(LokiHp);
}


void HpBar::SetLokiHP()
{
	LokiHp = Loki::MainBoss->GetLokiHp();
}

void HpBar::Renders(int _Hp)
{

	for (int i = 32; i >= 0; i--) {
		if (LokiHp == i) {
			if (i == 0) {
				HpbarRender->Death();
				HpbarBackRender->Death();
			}
			int j = 5;
			HpbarBackRender->SetScale({ static_cast<float>(i*10), 96 });
			HpbarBackRender->SetPosition({ (static_cast<float>(i)-32)*j,0 });
		}
	}
	
	
}