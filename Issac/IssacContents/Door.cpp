#include "Door.h"
#include "Isaac.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCore.h>

Door::Door()
{
}

Door::~Door()
{
}


void Door::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize();


	GameEngineRender* Render = CreateRender("Door_Down.bmp", IsaacRenderOrder::Door);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half() -float4({0,-240}));
	Render->SetScale({250,250});

	DoorCol = CreateCollision(IsaacCollisionOrder::Door);
	DoorCol->SetDebugRenderType(CollisionType::CT_Rect);
	DoorCol->SetPosition({630,600});
	DoorCol->SetScale({ 50,50 });
}

void Door::Update(float _DeltaTime)
{/*
	if (true == Isaac::MainPlayer->GetIsaacCollision()->Collision({ .TargetGroup = static_cast<int>(IsaacCollisionOrder::Door),
	  .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		asd* newasd=GetLevel()->CreateActor

	}*/
}
 
void Door::Render(float _DeltaTime)
{
	DoorCol->DebugRender();
}

