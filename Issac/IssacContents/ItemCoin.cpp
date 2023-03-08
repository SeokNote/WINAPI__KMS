
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"

#include "ItemCoin.h"



ItemCoin::ItemCoin()
{

}

ItemCoin::~ItemCoin()
{
}


void ItemCoin::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Coins = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Coin.bmp"));
	Coins->Cut(4, 3);

}

bool LoadCoin = true;

void ItemCoin::Start()
{
	if (true == LoadCoin)
	{
		ImageLoad();
		LoadCoin = false;
	}
	CoinRender = CreateRender(IssacRenderOrder::Object);
	CoinRender->SetScale({ 100, 100 });

	CoinRender->CreateAnimation({ .AnimationName = "CoinLoad",  .ImageName = "Coin.bmp", .Start = 8, .End = 11, .InterTime = 0.03f, .Loop = false });
	CoinRender->CreateAnimation({ .AnimationName = "Coin",  .ImageName = "Coin.bmp", .Start = 0, .End = 5, .InterTime = 0.15f });
	CoinRender->ChangeAnimation("CoinLoad");
	{
		CoinCol = CreateCollision(IssacCollisionOrder::ItemCoin);
		CoinCol->SetScale({ 10, 10 });
		CoinCol->On();
		CoinCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemCoin::Update(float _DeltaTime)
{
	CoinLoadTime += _DeltaTime;
	if (CoinLoadTime > 0.13f)
	{
		CoinRender->ChangeAnimation("Coin");
	}
}

void ItemCoin::Render(float _DeltaTime)
{
	CoinCol->DebugRender();

}