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
	MonsterSetCol->SetPosition({ 640,1350 });
	MonsterSetCol->SetScale({ 100,30 });
}

void MonsterSet::Update(float _DeltaTime)
{
	if (true == Issac::MainPlayer->GetIssacCollision()->Collision({ .TargetGroup = static_cast<int>(IssacCollisionOrder::MonsterSetting),
	  .TargetColType = CT_Rect, .ThisColType = CT_Rect }))
	{
		int A = 0;
		MonsterOne* NewMonster1 = GetLevel()->CreateActor<MonsterOne>();
		NewMonster1->SetPos({ 600,1640 });

	}
}

void MonsterSet::Render(float _DeltaTime)
{
	MonsterSetCol->DebugRender();
}

