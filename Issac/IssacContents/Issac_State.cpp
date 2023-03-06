#include "Issac.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "ContentsEnums.h"


void Issac::ChangeState(IssacState _State)
{


	IssacState NextState = _State;
	IssacState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case IssacState::IDLE:
		IdleStart();
		break;
	case IssacState::MOVE:
		MoveStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case IssacState::IDLE:
		IdleEnd();
		break;
	case IssacState::MOVE:
		MoveEnd();
		break;
	default:
		break;
	}
}


void Issac::UpdateState(float _Time)
{

	switch (StateValue)
	{
	case IssacState::IDLE:
		IdleUpdate(_Time);
		break;
	case IssacState::MOVE:
		MoveUpdate(_Time);
		break;
	default:
		break;
	}


}





void Issac::IdleStart() {


	IssacHeadRender->ChangeAnimation(DirString + "HIdle");
	IssacBodyRender->ChangeAnimation(DirString + "BIdle");
//	DirCheck("HIdle");
	//DirCheck("BIdle");

}
void Issac::IdleUpdate(float _Time) //가만히 있을때 뭘해야할까
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove")|| GameEngineInput::IsPress("DownMove")|| GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IssacState::MOVE);
		return; 
	}
}
void Issac::IdleEnd() {


}

void Issac::MoveStart() {

	//DirCheck("HMove");
	//DirCheck("BMove");
	IssacHeadRender->ChangeAnimation(DirString +"HMove");
	IssacBodyRender->ChangeAnimation(DirString +"BMove");
}
void Issac::MoveUpdate(float _Time) {


	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove") && false == GameEngineInput::IsPress("DownMove") && false == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IssacState::IDLE);
		return; //최종 결정후 무조건 리턴
	}
	float4 Dir;
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		Dir += float4::Left;
	}
	if (true == GameEngineInput::IsPress("RightMove"))
	{
		Dir += float4::Right;
	}
	if (true == GameEngineInput::IsPress("DownMove"))
	{
		Dir += float4::Down;
	}
	if (true == GameEngineInput::IsPress("UpMove"))
	{
		Dir += float4::Up;
	}
	Dir.Normalize();
	MoveDir = Dir * MoveSpeed;
	SetMove(MoveDir);
}
void Issac::MoveEnd() {


}
