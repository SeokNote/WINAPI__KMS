#include "MonsterBase.h"
#include "Isaac.h"

MonsterBase::MonsterBase()
{
}

MonsterBase::~MonsterBase()
{
}

void MonsterBase::Start()
{
}

void MonsterBase::Update(float _DeltaTime)
{
}

void MonsterBase::Render(float _DeltaTime)
{
}

void MonsterBase::Movecalculation(float _DeltaTime, bool _IsValue)
{
	float4 M_Move = Isaac::MainPlayer->GetPos() - GetPos();
	M_Move.Normalize();
	if (true == _IsValue)
	{
		M_Move = float4::Zero;
	}

	SetMove(M_Move * 15.0f * _DeltaTime);

}
