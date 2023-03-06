#include "MonsterOne.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "ContentsEnums.h"


void MonsterOne::ChangeState(MonsterState _State)
{


	MonsterState NextState = _State;
	MonsterState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case MonsterState::IDLE:
		IdleStart();
		break;
	case MonsterState::MOVE:
		MoveStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case MonsterState::IDLE:
		IdleEnd();
		break;
	case MonsterState::MOVE:
		MoveEnd();
		break;
	default:
		break;
	}
}


void MonsterOne::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case MonsterState::IDLE:
		IdleUpdate(_Time);
		break;
	case MonsterState::MOVE:
		MoveUpdate(_Time);
		break;
	default:
		break;
	}


}





void MonsterOne::IdleStart() {


	MonsterOneRender->ChangeAnimation(DirString + "Idle");
//	DirCheck("HIdle");
//  DirCheck("BIdle");

}
void MonsterOne::IdleUpdate(float _Time) //가만히 있을때 뭘해야할까
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("DownMove") || GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(MonsterState::MOVE);
	}
}
void MonsterOne::IdleEnd() {


}

void MonsterOne::MoveStart() {

	//DirCheck("HMove");
	//DirCheck("BMove");
	MonsterOneRender->ChangeAnimation(DirString + "Move");
}

void MonsterOne::MoveUpdate(float _Time) {

}

void MonsterOne::MoveEnd() {


}
