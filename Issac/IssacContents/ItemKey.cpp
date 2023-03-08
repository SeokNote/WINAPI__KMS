
#include <GameEngineBase/GameEngineDirectory.h>

#include <GameEnginePlatform/GameEngineInput.h>


#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "Issac.h"
#include "ContentsEnums.h"

#include "ItemKey.h"



ItemKey::ItemKey()
{

}

ItemKey::~ItemKey()
{
}


void ItemKey::ImageLoad()
{
	GameEngineDirectory Dir;
	Dir.MoveParentToDirectory("ContentsResources");
	Dir.Move("ContentsResources");
	Dir.Move("Image");
	Dir.Move("Play");


	GameEngineImage* Key = GameEngineResources::GetInst().ImageLoad(Dir.GetPlusFileName("Key.bmp"));
	Key->Cut(2, 2);

}

bool LoadKey = true;

void ItemKey::Start()
{
	if (true == LoadKey)
	{
		ImageLoad();
		LoadKey = false;
	}
	KeyRender = CreateRender(IssacRenderOrder::Object);
	KeyRender->SetScale({ 70, 70 });

	KeyRender->CreateAnimation({ .AnimationName = "Key",  .ImageName = "Key.bmp", .Start = 0, .End = 0, .InterTime = 1.0f , .Loop = false });
	KeyRender->ChangeAnimation("Key");
	{
		KeyCol = CreateCollision(IssacCollisionOrder::ItemKey);
		KeyCol->SetScale({ 10, 10 });
		KeyCol->On();
		KeyCol->SetDebugRenderType(CollisionType::CT_Rect);
	}
}

void ItemKey::Update(float _DeltaTime)
{

}

void ItemKey::Render(float _DeltaTime)
{
	//KeyCol->DebugRender();
}