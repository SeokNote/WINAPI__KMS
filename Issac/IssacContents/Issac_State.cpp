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


//	IssacHeadRender->ChangeAnimation(DirString + "HMove");
//	IssacBodyRender->ChangeAnimation(DirString + "BMove");
//	DirCheck("HIdle");
	DirCheck("BIdle");

}
void Issac::IdleUpdate(float _Time) //������ ������ ���ؾ��ұ�
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

	DirCheck("HMove");
	DirCheck("BMove");
	//IssacHeadRender->ChangeAnimation(DirString +"HMove");
	//IssacBodyRender->ChangeAnimation(DirString +"BMove");
}
void Issac::MoveUpdate(float _Time) {


	if (false == GameEngineInput::IsPress("LeftMove") && false == GameEngineInput::IsPress("RightMove") && false == GameEngineInput::IsPress("DownMove") && false == GameEngineInput::IsPress("UpMove"))
	{
		ChangeState(IssacState::IDLE);
		return; //���� ������ ������ ����
	}
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _Time);
	}
	if (true == GameEngineInput::IsPress("RightMove"))
	{
		 SetMove(float4::Right * MoveSpeed * _Time);
	}
	if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _Time);
	}
	if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _Time);
	}
	DirCheck("HMove");
	DirCheck("BMove");

}
void Issac::MoveEnd() {


}
