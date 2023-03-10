#include "MonsterSet.h"
#include "Issac.h"
#include "ContentsEnums.h"

#include "MonsterOne.h"
#include "MonsterTwo.h"
#include "TestLevel.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
MonsterSet::MonsterSet()
{
}

MonsterSet::~MonsterSet()
{
}


void MonsterSet::Start()
{
	MonsterSetCol = CreateCollision(IssacCollisionOrder::MonsterSetting);
	MonsterSetCol->SetDebugRenderType(CollisionType::CT_Rect);
	MonsterSetCol->SetPosition({ 640,1580 });
	MonsterSetCol->SetScale({ 100,30 });
}

void MonsterSet::Update(float _DeltaTime)
{

}

void MonsterSet::Render(float _DeltaTime)
{
//	MonsterSetCol->DebugRender();
}

