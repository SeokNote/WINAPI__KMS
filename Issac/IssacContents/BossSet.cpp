#include "BossSet.h"
#include "Isaac.h"

#include "ContentsEnums.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>

BossSet::BossSet()
{
}

BossSet::~BossSet()
{
}


void BossSet::Start()
{
	BossSetCol = CreateCollision(IsaacCollisionOrder::BossSetting);
	BossSetCol->SetDebugRenderType(CollisionType::CT_Rect);
	BossSetCol->SetPosition({ 640,2280 });
	BossSetCol->SetScale({ 100,30 });
}

void BossSet::Update(float _DeltaTime)
{

}

void BossSet::Render(float _DeltaTime)
{
//	BossSetCol->DebugRender();
}

